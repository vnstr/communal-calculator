import QtQuick 2.15

Item {
    SettingsPanel {
        anchors.fill: parent

        mainRectangle.height: 128
        titleText: "Tariff"

        Component.onCompleted: {
            addSettingCell("Hot water")
            addSettingCell("Cold water")
        }
    }
}
