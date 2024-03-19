import QtQuick 2.15
import QtQuick.Layouts

Rectangle {
  property alias titleText: titleText.text

  signal inputFinished()

  id: mainRectangle

  color: "#f2a33c"
  radius: 12

  RowLayout {
    anchors.fill: parent

    Text {
      id: titleText

      Layout.alignment: Qt.AlignVCenter | Qt.AlignLeft
      Layout.leftMargin: 16

      color: "#fef1e2"
    }

    Item { Layout.fillWidth: true }

    DigitsTextInput {
      id: valueDigitsTextInput

      Layout.alignment: Qt.AlignVCenter | Qt.AlignRight
      Layout.rightMargin: 16

      Keys.onReturnPressed: {
        inputFinished()
      }
    }
  }
}
