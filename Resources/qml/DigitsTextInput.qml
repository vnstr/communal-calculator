import QtQuick 2.15

Rectangle {
  property alias textInput: textInput
  property alias hintText: hintText.text

  id: textInputRectangle

  width: 100
  height: 20
  radius: 8

  color: "#454444"

  TextInput {
    id: textInput

    anchors.fill: parent

    verticalAlignment: TextEdit.AlignVCenter
    horizontalAlignment: TextEdit.AlignHCenter

    color: "#eeeeee"

    validator: DoubleValidator {
      locale: "en_US"
      bottom: 0
      top: 99999999
    }

    Text {
      id: hintText

      anchors.centerIn: parent

      color: "#aaa"

      visible: !textInput.text
    }
  }
}
