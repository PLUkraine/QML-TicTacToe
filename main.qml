import QtQuick 2.9
import QtQuick.Window 2.2

import "ViewHelper.js" as ViewHelper

Window {
    id: root

    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")


    Component.onCompleted: {
        var rows = 3;
        var cols = 4;

        ViewHelper.spawnCells(root, rows, cols);
        ViewHelper.createBars(root, rows, cols);
    }

}
