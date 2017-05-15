import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0
import QtQuick.Window 2.2
import QtQuick.Controls.Universal 2.0

Item {
    id: item1

    ColumnLayout {
        id: columnLayout1
        height: 230
        anchors.top: parent.top
        anchors.topMargin: 10
        anchors.right: parent.right
        anchors.rightMargin: 10
        anchors.left: parent.left
        anchors.leftMargin: 10


        RowLayout {
            width: parent.width
            spacing: 20
            height: 30
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            Layout.fillWidth: false

            Label {
                id: label1
                width: 70
                text: qsTr("First Name")
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignLeft
            }

            TextField {
                id: textField1
                width: 600
                height: 22
                text: qsTr("")
            }

        }

        RowLayout {
            width: parent.width
            height: 30
            Layout.fillWidth: true
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            Label {
                id: label2
                width: 70
                text: qsTr("Name")
                horizontalAlignment: Text.AlignLeft
                verticalAlignment: Text.AlignVCenter
            }

            TextField {
                id: textField2
                text: qsTr("")
            }
            spacing: 20
        }

        RowLayout {
            width: parent.width
            height: 30
            Layout.fillWidth: true
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            Label {
                id: label3
                width: 70
                text: qsTr("Password")
                horizontalAlignment: Text.AlignLeft
                verticalAlignment: Text.AlignVCenter
            }

            TextField {
                id: textField3
                text: qsTr("")
            }
            spacing: 20
        }

        RowLayout {
            width: parent.width
            height: 10
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            spacing: 20
            Layout.fillWidth: true

            Button {
                id: button1
                height: 12
                text: qsTr("Add new User")
            }

            Button {
                id: button2
                height: 10
                text: qsTr("connect ")
            }

            Switch {
                id: switch1
                text: qsTr("Switch")
            }
        }
    }

    Text {
        id: text1
        x: 148
        y: 284
        width: 409
        height: 57
        text: "Please Fill  alll field an choose ! "
        styleColor: "#d4b4b4"
        font.pixelSize: 24
        style: Text.Raised
        font.family: "Arial"
        textFormat: Text.AutoText
        wrapMode: Text.WordWrap
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
    }
}
