import QtQuick.Controls 2.0
import QtQuick 2.0


ApplicationWindow {
    title: "BrNocBreak"
    visible: true

//     signal setNextText(var s)
//     onSetNextText: 
//     {
//         console.log("psi")
//         //textNext.text = text
//     }

    function setNextText(s)
    {
        nextName.text = s
        return "OK"
    }
    
    Image {
        id: root
        source: "background.jpg"

        anchors.fill: parent
        

        Image {
            id: brnenka
            source: "brnenka2.png"

            anchors.bottom: root.bottom
            anchors.left: root.left

            anchors.bottomMargin: 40
            anchors.leftMargin: 40

            fillMode: Image.PreserveAspectFit
            width: clock.x - 80
        }

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
            wrapMode: TextEdit.Wrap

            text: ""
            focus: true
            cursorDelegate: Rectangle{}

            Keys.onPressed: {
                if ((event.key == Qt.Key_R) && (event.modifiers & Qt.ControlModifier))
                    text = ""
            }
        }

        Clock
        {
            id: clock
            color: "white"
            font.pointSize: root.width / 15

            anchors.bottom: root.bottom
            anchors.bottomMargin: root.height/20
            anchors.horizontalCenter: parent.horizontalCenter
        }
    }
    
    Component.onCompleted: console.log("psi stekaji")
}
