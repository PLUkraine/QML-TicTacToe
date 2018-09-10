import QtQuick 2.9
import QtQuick.Window 2.2

import TicTacToe 1.0

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
    GameBoard {
        id: gameBoard

        anchors.top: menuBar.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom

        onPlayerChanged: {
            currentPlayerView.changePlayer(isXTurn)
        }
    }
}
