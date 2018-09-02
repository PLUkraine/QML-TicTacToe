import QtQuick 2.0

Rectangle {
    id: root

    property alias color: root.color
    property double barWidth
    property double barHeight
    property double barX
    property double barY

    width: barWidth
    height: barHeight
    x: barX
    y: barY

    color: "black"
}
