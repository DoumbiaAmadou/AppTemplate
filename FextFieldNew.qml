import QtQuick 2.0


Rectangle {
    id: textField

    width: parent.width
    height: textInput.height * 1.8

    border.width: 3
    border.color: "lightgrey"
    radius: height/4
    smooth: true

    property alias text: textInput.text
    property int echoMode: TextInput.Normal

    signal textChanged(string text)

    TextInput {
        id: textInput

        width: parent.width - (2 * font.pointSize)
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter

        font.pointSize: 17

        color: "black"
        echoMode: textField.echoMode

        onTextChanged: textField.textChanged(text)

        onFocusChanged: {
            if(focus){
                textField.border.color = "#569ffd"
            }else{
                textField.border.color = "lightgray"
            }
        }
    }
}
