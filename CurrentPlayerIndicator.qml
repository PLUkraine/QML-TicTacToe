import QtQuick 2.0

Item {
    id: root
    property color xColor: "red"
    property color oColor: "blue"

    function changePlayer(isXPlayer) {
        rectangle.color = isXPlayer ? root.xColor : root.oColor
    }

    Text {
        anchors.left: parent.left
        anchors.verticalCenter: parent.verticalCenter
        text: qsTr("Turn")
    }
    Rectangle {
        id: rectangle

        anchors.right: parent.right
        width: parent.height
        height: parent.height
        color: xColor

        Behavior on color {
            ColorAnimation { target: rectangle; duration: 300 }
        }
    }


}
