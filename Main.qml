import QtQuick
import QtQuick.Controls
import SimplePomodoro

Window {
    minimumWidth: 640
    minimumHeight: 480
    maximumWidth: minimumWidth
    maximumHeight: minimumHeight
    visible: true
    title: qsTr("Simple Pomodoro")
    color: "#424949"

    PomodoroTimer {
        id: pomodoroTimer
        onTimeUpdate: timeText.text = pomodoroTimer.minutes + ":" + pomodoroTimer.seconds
    }

    Text{
        id: timeText
        anchors.top: parent.top
        anchors.topMargin: 100
        anchors.horizontalCenter: parent.horizontalCenter
        text: "00:00"
        font.pixelSize: 100
    }

    Button {
        text: "Start"
        anchors.left: parent.left
        anchors.leftMargin: 20
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 20

        width: 100
        height: 60
        font.pixelSize: 20
        onClicked: pomodoroTimer.start()
    }
    Button {
        text: "Stop"
        anchors.right: parent.right
        anchors.rightMargin: 20
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 20

        width: 100
        height: 60
        font.pixelSize: 20
        onClicked: pomodoroTimer.stop()
    }

}
