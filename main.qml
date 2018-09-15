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
    statusBar: AppStatusBar {
        id: appStatusBar
    }

    // container for the actual game board
    GameBoard {
        id: gameBoard

        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom

        onPlayerChanged: {
            appStatusBar.currentPlayerView.changePlayer(isXTurn)
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
    Action {
        id: quitApplicationAction
        text: "&Exit"
        shortcut: StandardKey.Redo
        onTriggered: {
            Qt.quit();
        }
    }
    NewGameDialog {
        id: newGameDialog

        onStartNewGame: {
            gameBoard.startNewGame(rows, cols, cellsToWin, opponentType);
            gameBoard.focus = true;
        }
    }

    Component.onCompleted: {
        gameBoard.focus = true;
    }
}
