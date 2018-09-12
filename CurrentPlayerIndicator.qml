import QtQuick 2.0

Rectangle {
    id: root

    property color xColor: "red"
    property color oColor: "blue"

    function changePlayer(isXPlayer) {
        root.color = isXPlayer ? root.xColor : root.oColor
    }

    color: xColor

    Behavior on color {
        ColorAnimation { target: root; duration: 300 }
    }
}
