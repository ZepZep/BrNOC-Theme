import QtQuick 2.0
import QtQml 2.0

Text {
    id: clock
    text: "00:00"

    function updateTime()
    {
        clock.text = new Date().toLocaleTimeString(Qt.locale("de_DE"), "hh:mm:ss")
    }

    Timer
    {
        id: clockTimer
        interval: 500
        repeat: true
        running: true

        onTriggered: updateTime()
    }

    Component.onCompleted: updateTime()
}
