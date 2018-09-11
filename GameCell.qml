import QtQuick 2.0

Rectangle {
    id: root
    property real disabledDim: 1.0
    property int row: -1
    property int col: -1

    signal activated(variant sender)

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
