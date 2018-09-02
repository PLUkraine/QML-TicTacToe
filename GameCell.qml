import QtQuick 2.0

Rectangle {
    id: root
    signal activated(variant sender)

    MouseArea {
        id: mouseArea
        anchors.fill: parent

        onClicked: {
            if (root.state === "blocked") return;

            root.activated(root);
        }
    }

    states: [
        State {
            name: "clickable"
            PropertyChanges {
                target: root
                color: "white"
            }
        },
        State {
            name: "blocked"
            PropertyChanges {
                target: root
                color: "lightgray"
            }
        },
        State {
            name: "xState"
            PropertyChanges {
                target: root
                color: "red"
            }
        },
        State {
            name: "oState"
            PropertyChanges {
                target: root
                color: "blue"
            }
        }
    ]
}
