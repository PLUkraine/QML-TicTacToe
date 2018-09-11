import QtQuick 2.0

Rectangle {
    id: root
    property bool enableMoveAnimations: false
    property real disabledDim: 1.0
    property int row: -1
    property int col: -1

    signal activated(variant sender)

    border.color: "black"
    border.width: 0.5

    onEnabledChanged: {
        disabledDim = !enabled ? 1.5 : 1.0
    }

    MouseArea {
        id: mouseArea
        anchors.fill: parent

        onClicked: {
            if (root.state !== "clickable") return;

            root.activated(root);
        }
    }

    Behavior on color {
        ColorAnimation { target: root; duration: 150 }
    }
    Behavior on x {
        enabled: root.enableMoveAnimations
        NumberAnimation { duration: 300 }
    }
    Behavior on y {
        enabled: root.enableMoveAnimations
        NumberAnimation { duration: 300 }
    }

    states: [
        State {
            name: "clickable"
            PropertyChanges {
                target: root
                color: Qt.darker("white", disabledDim)
            }
        },
        State {
            name: "xState"
            PropertyChanges {
                target: root
                color: Qt.darker("red", disabledDim)
            }
        },
        State {
            name: "oState"
            PropertyChanges {
                target: root
                color: Qt.darker("blue", disabledDim)
            }
        }
    ]
}
