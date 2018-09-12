import QtQuick 2.0

import QtQuick.Controls 1.4
import QtQuick.Layouts 1.1

StatusBar {
    id: root

    property alias currentPlayerView: currentPlayerView
    property alias gameStatusText: gameStatus.text

    RowLayout {
        Label {
            id: gameStatus
            text: "Running"
        }

        Rectangle {
            color: "black"
            width: 1
            height: 15
        }

        Label {
            text: "Turn"
        }

        CurrentPlayerIndicator {
            id: currentPlayerView

            width: 15
            height: 15
        }
    }
}
