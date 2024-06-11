import QtQuick
import QtQuick.Controls
import SimplePomodoro



Window {
    id: root
    flags: Qt.FramelessWindowHint
    minimumWidth: 640
    minimumHeight: 480
    maximumWidth: minimumWidth
    maximumHeight: minimumHeight
    visible: true
    title: qsTr("Simple Pomodoro")
    color: "transparent"

    property bool dragging: false
    property var startMousePosition: Qt.point(0,0)
    property var startWindowPosition: Qt.point(0,0)

    Rectangle{
        color: "#118ab2"
        radius: 20
        anchors.fill: parent
    }

    MouseArea{
        id: mouseArea
        anchors.fill: parent
        visible: true
        cursorShape: Qt.OpenHandCursor

        onPressed: {
            root.dragging = true
            root.startMousePosition = Qt.point(mouseX, mouseY)
            root.startWindowPosition = Qt.point(root.x, root.y)
        }

        onPositionChanged: {
            if(root.dragging) {
                var deltaX = mouseX - root.startMousePosition.x
                var deltaY = mouseY - root.startMousePosition.y
                root.x = root.startWindowPosition.x + deltaX
                root.y = root.startWindowPosition.y + deltaY
            }
        }

        onReleased: {
            root.dragging = false
        }
    }

    PomodoroTimer {
        id: pomodoroTimer
        onTimeUpdate: timeText.text = pomodoroTimer.minutes + ":" + pomodoroTimer.seconds
        onCycleChanged: counterText.text = pomodoroTimer.cycle
    }

    Text{
        id: timeText
        anchors.top: parent.top
        anchors.topMargin: 100
        anchors.horizontalCenter: parent.horizontalCenter
        text: "00:00"
        font.pixelSize: 100
    }
    Rectangle {
        width: 70
        height: 70
        anchors.margins: 20
        anchors.top: parent.top
        anchors.right: parent.right
        color:"#118ab2"
        Text{
            id: counterText
            text: "0"
            font.pixelSize: 40
            anchors.horizontalCenter: parent.horizontalCenter
        }

    }

    component UiButtons: Button{
        property color buttonColor: "#ffffff"
        anchors.bottom: parent.bottom
        font.pixelSize: 20
        background: Rectangle{
            implicitWidth: 100
            implicitHeight: 60
            color: buttonColor
            border.color: "#000000"
            border.width: 2
            radius: 8
        }

    }


    UiButtons {
        text: "Start"
        anchors.left: parent.left
        anchors.leftMargin: 20
        anchors.bottomMargin: 20
        buttonColor: "#06d6a0"
        onClicked: pomodoroTimer.start()
    }
    UiButtons {
        text: "Stop"
        anchors.right: parent.right
        anchors.rightMargin: 20
        anchors.bottomMargin: 20
        buttonColor: "#ef476f"
        onClicked: pomodoroTimer.stop()
    }

}
