import QtQuick.Controls 2.0
import QtQuick 2.0


ApplicationWindow {
    title: "BrNocBreak"
    visible: true

    Image {
        id: root
        source: "background.jpg"

        anchors.fill: parent

        Text {
            id: textNext
            color: "white"
            text: "Následuje:"
            anchors.horizontalCenter: parent.horizontalCenter
            font.pointSize: root.height / 20
            y: root.height/7
        }

        Rectangle
        {
            id: underline

            anchors.top: textNext.bottom
            anchors.topMargin: 10
            anchors.horizontalCenter: parent.horizontalCenter

            width: textNext.width*2
            height: 4

            color: "transparent"
            border.color: "white"
            border.width: 100
        }

        TextArea {
            id: nextName
            color: "white"
            anchors.horizontalCenter: parent.horizontalCenter
            font.pointSize: root.height / 15
            anchors.top: underline.bottom
            anchors.topMargin: 20
            horizontalAlignment:  TextInput.AlignHCenter

            text: ""
        }

        Clock
        {
            color: "white"
            font.pointSize: root.height / 10

            anchors.bottom: root.bottom
            anchors.bottomMargin: root.height/20
            anchors.horizontalCenter: parent.horizontalCenter
        }
    }
}
