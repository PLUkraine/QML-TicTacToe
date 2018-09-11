import QtQuick 2.0
import QtQuick.Dialogs 1.3

import TicTacToe 1.0
import "ViewHelper.js" as ViewHelper


Item {
    id: root
    signal playerChanged(bool isXTurn)

    function delay(delayTime, cb) {
        timer.interval = delayTime;
        timer.repeat = false;
        timer.triggered.connect(cb);
        timer.start();
    }
    function randomIntBetween(low, high) {
        return Math.floor(low + Math.random() * (high - low));
    }

    GameController {
        id: gameController

        onPlayerChanged: root.playerChanged(isXPlayer)
        onGameIsOver: {
            root.enabled = false;

            // restart game
            root.delay(1000, function() {
                ViewHelper.newGame(root, gameController, randomIntBetween(3, 5), randomIntBetween(3, 6), 3);
                root.enabled = true;
            });
        }
    }
    Timer {
        id: timer
    }



    Component.onCompleted: {
        var rows = 5;
        var cols = 5;
        var cellsToWin = 4;

        ViewHelper.initialize(root, gameController, 40);
        ViewHelper.newGame(root, gameController, rows, cols, cellsToWin);
    }
}
