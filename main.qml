import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.3

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

        CurrentPlayerIndicator {
            id: currentPlayerView

            anchors.right: parent.right
            width: 100
            height: parent.height
        }
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
            winDialog.text = "Game is over.\n" + ViewHelper.gameStateToString(result);
            winDialog.visible = true;
            cellHolder.enabled = false;
        }
        onPlayerChanged: {
            currentPlayerView.changePlayer(isXPlayer)
        }
    }
    MessageDialog {
        id: winDialog

        modality: "WindowModal"
    }

    Component.onCompleted: {
        var rows = 3;
        var cols = 3;

        ViewHelper.spawnCells(cellHolder, gameController, rows, cols);
        ViewHelper.createBars(cellHolder, rows, cols);
        gameController.newGame(rows, cols, 3);
    }
}
