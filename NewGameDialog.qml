import QtQuick 2.0
import QtQuick.Controls 1.2
import QtQuick.Dialogs 1.2
import QtQuick.Layouts 1.1

Dialog {
    id: spinboxDialog

    signal startNewGame(int rows, int cols, int cellsToWin)

    modality: Qt.WindowModal
    title: qsTr("Start new game")
    standardButtons: Dialog.Ok | Dialog.Cancel
    onAccepted: startNewGame(rowsSpinbox.value,
                             colsSpinbox.value,
                             winCountSpinbox.value)

    ColumnLayout {
        id: column
        width: parent ? parent.width : 100

        RowLayout {
            Layout.columnSpan: 2
            Layout.alignment: Qt.AlignHCenter
            Label {
                text: qsTr("Rows")
            }
            SpinBox {
                id: rowsSpinbox
                minimumValue: 2
                maximumValue: 5
                value: 3
            }
        }
        RowLayout {
            Layout.columnSpan: 2
            Layout.alignment: Qt.AlignHCenter
            Label {
                text: qsTr("Cols")
            }
            SpinBox {
                id: colsSpinbox
                minimumValue: 2
                maximumValue: 5
                value: 3
            }
        }
        RowLayout {
            Layout.columnSpan: 2
            Layout.alignment: Qt.AlignHCenter
            Label {
                text: qsTr("Cells to win")
            }
            SpinBox {
                id: winCountSpinbox
                minimumValue: 2
                maximumValue: Math.min(5, rowsSpinbox.value, colsSpinbox.value)
                value: 3
            }
        }
    }
}
