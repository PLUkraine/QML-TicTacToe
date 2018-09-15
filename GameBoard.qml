import QtQuick 2.0
import QtQuick.Dialogs 1.3

import TicTacToe 1.0
import "ViewHelper.js" as ViewHelper


Item {
    id: root
    signal playerChanged(bool isXTurn)


    function randomIntBetween(low, high) {
        return Math.floor(low + Math.random() * (high - low));
    }
    function startNewGame(rows, cols, cellsToWin, opponentType) {
        ViewHelper.newGame(root, gameController, rows, cols, cellsToWin, opponentType);
        root.enabled = true;
    }

    onFocusChanged: {
        var anyCell = ViewHelper.anyCell();
        if (focus && anyCell && anyCell.enabled) {
            anyCell.focus = true;
        }
    }

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

        ViewHelper.initialize(root, gameController, 40);
        ViewHelper.newGame(root, gameController, rows, cols, cellsToWin, GameOpponent.NONE);
    }
}
