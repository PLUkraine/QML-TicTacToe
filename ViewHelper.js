.import TicTacToe 1.0 as GameLogic

var __cells__ = [];
var __currentRows__ = 0;
var __currentCols__ = 0;

function initialize(root, controller, cellsCapacity) {
    __initCells__(root, controller, cellsCapacity);

    controller.cellChanged.connect(__onCellChangedCallback__);
}

function newGame(root, controller, rows, cols, cellsToWin) {
    __cells__.forEach(__resetCell__);

    console.assert(rows*cols < __cells__.length);
    __newGameCells__(root, rows, cols);
    __currentRows__ = rows;
    __currentCols__ = cols;

    controller.newGame(rows, cols, cellsToWin);
    __cells__.forEach(function(cell) {
        cell.enableMoveAnimations = false;
    })
}

function gameStateToString(gameState) {
    switch (gameState) {
    case GameLogic.GameState.STATE_NOTHING:
        return "Running";
    case GameLogic.GameState.STATE_DRAW:
        return "Draw";
    case GameLogic.GameState.STATE_X_WIN:
        return "X is winner";
    case GameLogic.GameState.STATE_O_WIN:
        return "O is winner";
    default:
        console.error("Wrong state: " + gameState);
        console.assert(false);
        break;
    }
    return "ERROR"
}

function __onCellChangedCallback__(index, newState) {
    var cell = __cells__[index];

    switch (newState) {
    case GameLogic.CellState.EMPTY:
        cell.state = "clickable";
        break;
    case GameLogic.CellState.X:
        cell.state = "xState";
        break;
    case GameLogic.CellState.O:
        cell.state = "oState";
        break;
    default:
        console.error("Wrong state: " + gameState);
        console.assert(false);
        break;
    }
}

function __newGameCells__(root, rows, cols) {
    for (var i=0; i<rows; ++i) {
        for (var j=0; j<cols; ++j) {
            (function() {
                // closure to save values of i and j
                var ii = i;
                var jj = j;
                var index = ii * cols + jj;

                var cell = __cells__[index];
                cell.row = ii;
                cell.col = jj;
                cell.x = Qt.binding(function() {return jj * root.width / cols});
                cell.y = Qt.binding(function() {return ii * root.height / rows});
                cell.width = Qt.binding(function() {return root.width / cols});
                cell.height = Qt.binding(function() {return root.height / rows});
                cell.state = "clickable";
                cell.enabled = true;
            })();
        }
    }
}

function __resetCell__(cell) {
    cell.enableMoveAnimations = true;
    cell.x = 0;
    cell.y = 0;
    cell.row = -1;
    cell.col = -1;
    cell.width = 0;
    cell.height = 0;
    cell.state = "clickable";
    cell.enabled = false;
}

function __initCells__(root, controller, capacity) {
    var cellComponent = Qt.createComponent("GameCell.qml");

    for (var i=0; i<capacity; ++i) {
        var cell = cellComponent.createObject(root, { "state": "clickable" });
        cell.activated.connect(function(sender) {
            if (!sender.enabled) return;

            controller.makeMove(controller.getIndex(sender.row, sender.col));
        });
        cell.navigateTo.connect(function (sender, direction) {
           console.log("HAHA ya choto ne xochu iti tuda " + direction);
        });
        __cells__.push(cell);
    }
}
