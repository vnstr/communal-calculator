import QtQuick 2.15
import QtQuick.Layouts

Item {
    property alias mainRectangle: mainRectangle
    property alias panelRectangleHeight: mainRectangle.height
    property alias titleText: titleText.text

    function addSettingCell(name) {
        mainRectangleLayout.addSettingCell(name)
    }

    ColumnLayout {
        id: contentLayout

        anchors.fill: parent

        Text {
            id: titleText
            color: "#fef1e2"
        }

        Rectangle {
            id: mainRectangle

            Layout.fillWidth: true

            color: "#454444"
            radius: 12

            ColumnLayout {
                id: mainRectangleLayout

                property list<SettingCell> settingCellsList

                function addSettingCell (name) {
                    var obj = settingCellComponent.createObject(mainRectangleLayout)
                    obj.titleText = name
                    settingCellsList.push(obj)
                }

                anchors.fill: parent

                Component {
                    id: settingCellComponent

                    SettingCell {
                        height: 40
                        Layout.fillWidth: true
                    }
                }
            }
        }
    }
}
