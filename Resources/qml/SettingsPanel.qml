import QtQuick 2.15
import QtQuick.Layouts

Item {
    property alias panelRectangleHeight: mainRectangle.height

    ColumnLayout {
        id: contentLayout

        anchors.fill: parent

        Text {
            id: titleText

            text: "Tariff"
            color: "#fef1e2"
        }

        Rectangle {
            id: mainRectangle

            Layout.fillWidth: true

            color: "#454444"
            radius: 12
        }
    }
}
