.pragma library

function spawnCells(root, controller, rows, cols, CellState) {
    var cellComponent = Qt.createComponent("GameCell.qml");

    // create cells
    for (var i=0; i<rows; ++i) {
        for (var j=0; j<cols; ++j) {
            (function() {
                // closure to save values of i and j
                var ii = i;
                var jj = j;

                var cell = cellComponent.createObject(root,
                                                      {
                                                          // recompute values when root size changes
                                                          "x": Qt.binding(function() {return jj * root.width / cols}),
                                                          "y": Qt.binding(function() {return ii * root.height / rows}),
                                                          "width": Qt.binding(function() {return root.width / cols}),
                                                          "height": Qt.binding(function() {return root.height / rows}),
                                                          "state": "clickable"
                                                      });
                cell.activated.connect(function(sender) {
                    controller.makeMove(ii, jj);
                });
                controller.cellChanged.connect(function(row, col, newState) {
                    if (ii !== row || jj !== col) return;

                    switch (newState) {
                    case CellState.EMPTY:
                        cell.state = "clickable";
                        break;
                    case CellState.X:
                        cell.state = "xState";
                        break;
                    case CellState.O:
                        cell.state = "oState";
                        break;
                    default:
                        console.error("Wrong state: " + gameState);
                        console.assert(false);
                        break;
                    }
                });
            })();
        }
    }
}

function createBars(root, rows, cols) {
    // create intercell bars
    var barWidth = 3;
    var barComponent = Qt.createComponent("Bar.qml");

    // horizontal
    for (var i=1; i<rows; ++i) {
        (function() {
            // closure to save values of i
            var ii = i;

            barComponent.createObject(root,
                                      {
                                          // recompute values when root size changes
                                          "x": 0,
                                          "y": Qt.binding(function() {return (ii * root.height / rows) - barWidth/2}),
                                          "width": Qt.binding(function() {return root.width}),
                                          "height": barWidth
                                      });
        })();
    }
    // vectical
    for (var j=1; j<cols; ++j) {
        (function() {
            // closure to save values of j
            var jj = j;

            barComponent.createObject(root,
                                      {
                                          // recompute values when root size changes
                                          "x": Qt.binding(function () {return (jj * root.width / cols) - barWidth/2}),
                                          "y": 0,
                                          "width": barWidth,
                                          "height": Qt.binding(function() {return root.height}),
                                      });
        })();
    }
}

function gameStateToString(gameState, GameState) {
    switch (gameState) {
    case GameState.STATE_DRAW:
        return "Draw";
    case GameState.STATE_X_WIN:
        return "X is winner";
    case GameState.STATE_O_WIN:
        return "O is winner";
    default:
        console.error("Wrong state: " + gameState);
        console.assert(false);
        break;
    }
    return "ERROR"
}
