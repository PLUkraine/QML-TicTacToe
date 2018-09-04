import QtQuick 2.9
import QtQuick.Window 2.2

import TicTacToe 1.0

import "ViewHelper.js" as ViewHelper

Window {
    id: root

    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    // mock menu bar
    Rectangle {
        id: menuBar
        x: 0
        y: 0
        width: parent.width
        height: 50
        color: "grey"
    }

    // container for the actual game board
    Item {
        id: cellHolder
        anchors.top: menuBar.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom
    }

    GameController {
        id: gameController

        onGameIsOver: {
            console.log("Game is over");
            cellHolder.enabled = false
        }
    }


    Component.onCompleted: {
        var rows = 5;
        var cols = 3;

        ViewHelper.spawnCells(cellHolder, gameController, rows, cols);
        ViewHelper.createBars(cellHolder, rows, cols);
        gameController.newGame(rows, cols, 3);
    }
}
