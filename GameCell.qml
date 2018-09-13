import QtQuick 2.0

Rectangle {
    id: root
    property bool enableMoveAnimations: false

    property real disabledDim: 1.0
    property real focusDim: 0.0
    property real maxFocusDim: 0.3

    property int row: -1
    property int col: -1

    signal navigateTo(variant sender, int direction)
    signal activated(variant sender)

    border.color: "black"
    border.width: 0.5

    onEnabledChanged: {
        disabledDim = enabled ? 1.0 : 1.5
    }
    onFocusChanged: {
        focusDim = root.activeFocus ? maxFocusDim : 0.0;
    }

    MouseArea {
        id: mouseArea
        anchors.fill: parent

        onClicked: {
            root.focus = true;
            if (root.state !== "clickable") return;

            root.activated(root);
        }
    }
    Keys.onPressed: {
        event.accepted = true;
        if (event.key === Qt.Key_Return) {
            if (root.state !== "clickable") return;
            activated(root);
        }
        else {
            navigateTo(root, event.key);
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
    Timer {
        id: colorDimTimer
        interval: 1000
        repeat: true
        running: root.activeFocus

        onTriggered: {
            focusDim = focusDim === 0.0 ? maxFocusDim : 0.0
        }
    }

    states: [
        State {
            name: "clickable"
            PropertyChanges {
                target: root
                color: Qt.darker("white", disabledDim + focusDim)
            }
        },
        State {
            name: "xState"
            PropertyChanges {
                target: root
                color: Qt.darker("red", disabledDim + focusDim)
            }
        },
        State {
            name: "oState"
            PropertyChanges {
                target: root
                color: Qt.darker("blue", disabledDim + focusDim)
            }
        }
    ]
}
