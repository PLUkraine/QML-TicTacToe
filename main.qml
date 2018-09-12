import QtQuick 2.9
import QtQuick.Controls 1.4

import TicTacToe 1.0

ApplicationWindow {
    id: root

    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    menuBar: MenuBar {
        Menu {
            title: "&Game"
            MenuItem { action: newGameAction }
            MenuItem { action: quitApplicationAction }
        }
    }

    Action {
        id: newGameAction
        text: "&New Game..."
        shortcut: StandardKey.New
        onTriggered: {
            newGameDialog.visible = true;
        }
    }
    NewGameDialog {
        id: newGameDialog

        onStartNewGame: {
            gameBoard.startNewGame(rows, cols, cellsToWin);
        }
    }
    Action {
        id: quitApplicationAction
        text: "&Exit"
        shortcut: StandardKey.Redo
        onTriggered: {
            Qt.quit();
        }
    }


    // mock menu bar
    Rectangle {
        id: mockedMenuBar
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

        anchors.top: mockedMenuBar.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom

        onPlayerChanged: {
            currentPlayerView.changePlayer(isXTurn)
        }
    }
}
