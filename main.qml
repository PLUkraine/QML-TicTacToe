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

        Component.onCompleted: {
            var rows = 3;
            var cols = 4;

            ViewHelper.spawnCells(cellHolder, rows, cols);
            ViewHelper.createBars(cellHolder, rows, cols);
        }
    }

    GameController {
        id: gameController

        Component.onCompleted: {
            gameController.sayHello();
        }
    }



}
