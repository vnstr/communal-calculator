import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts

Page {
  id: settingsView

  background: Rectangle {
    gradient: Gradient {
      GradientStop { position: 0.0; color: "#585959" }
      GradientStop { position: 1.0; color: "#656666" }
    }
  }

  ColumnLayout {
      QtObject {
        id: internal
        property int panelsAlignment: Qt.AlignTop | Qt.AlignHCenter
        property int leftRightMargin: 16
        property int panelRectangleHeight: 128
      }

      id: panelsLayout

      anchors.fill: parent

      SettingsPanel {
          Layout.alignment: internal.panelsAlignment
          Layout.leftMargin: internal.leftRightMargin
          Layout.topMargin: 16
          Layout.rightMargin: internal.leftRightMargin
          Layout.fillWidth: true

          panelRectangleHeight: internal.panelRectangleHeight
      }
  }
}
