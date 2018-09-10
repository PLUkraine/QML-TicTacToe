import QtQuick 2.0
import QtQuick.Dialogs 1.3

import TicTacToe 1.0
import "ViewHelper.js" as ViewHelper


Item {
    id: root
    signal playerChanged(bool isXTurn)

    GameController {
        id: gameController

        onPlayerChanged: root.playerChanged(isXPlayer)
        onGameIsOver: {
            root.enabled = false;
        }
    }

    Component.onCompleted: {
        var rows = 5;
        var cols = 5;
        var cellsToWin = 4;

        ViewHelper.spawnCells(root, gameController, rows, cols);
        ViewHelper.createBars(root, rows, cols);
        gameController.newGame(rows, cols, cellsToWin);
    }
}
