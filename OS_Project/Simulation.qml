import QtQuick 2.11
import QtQuick.Window 2.11
import QtQuick.Controls 2.5
import QtQuick.Controls.Styles 1.4


Item {
    id: process
    focus: true
    property var scheduledId
    property var ganttChart
    property var waitingTime
    function setModel(model)
    {
        processRepeater.model = model
        processRepeater.setProcesses()
    }
    function stateFaded(index)
    {
        processRepeater.itemAt(index).state = "faded"
        drawTimer.it = index
    }
    function stateDefault(index)
    {
        processRepeater.itemAt(index).state = "original"
    }
    Keys.onPressed: {
        if(event.key === Qt.Key_Right)
        {
            if(!play_rec.played)
            {
                if(buttons.itr < process.scheduledId.length - 1 && buttons.itr >= 0)
                {
                    attention.visible = false
                    process.stateDefault(buttons.itr)
                    buttons.itr++
                    process.stateFaded(buttons.itr)
                    processSelected.text = "Current Process is : " + process.scheduledId[buttons.itr]
                }
                else
                {
                    attention.visible = false
                    process.stateDefault(process.scheduledId.length - 1)
                    buttons.itr = 0
                    process.stateFaded(buttons.itr)
                    processSelected.text = "Current Process is : " + process.scheduledId[buttons.itr]
                }
            }
            else
            {
                attention.visible = true
            }
        }
        else if(event.key === Qt.Key_Left)
        {
            if(!play_rec.played)
            {
                if(buttons.itr > 0)
                {
                    attention.visible = false
                    process.stateDefault(buttons.itr)
                    buttons.itr--
                    process.stateFaded(buttons.itr)
                   processSelected.text = "Current Process is : " + process.scheduledId[buttons.itr]
                }
                else
                {
                    attention.visible = false
                    process.stateDefault(0)
                    buttons.itr = process.scheduledId.length - 1
                    process.stateFaded(buttons.itr)
                    processSelected.text = "Current Process is : " + process.scheduledId[buttons.itr]
                }
            }
            else
            {
                attention.visible = true
            }
        }
        else if(event.key === Qt.Key_Enter - 1)
        {
            if(play_rec.played)
            {
                play.source = "images/icons/play.png"
                drawTimer.stop()
                buttons.itr = drawTimer.it - 1
                play_rec.played = false
                attention.visible = false
            }
            else
            {
                play.source = "images/icons/pause.png"
                drawTimer.start()
                play_rec.played = true
            }
        }
    }
    Timer{
        id: drawTimer
        repeat: true
        interval: 1000
        property int it: 0
        onTriggered: {
            if(it != 0)
            {
                processRepeater.itemAt(it-1).state = "original"
            }
            else
            {
                processRepeater.itemAt(scheduledId.length - 1).state = "original"
            }
            processRepeater.itemAt(it).state = "faded"
            processSelected.text = "Current Process is : " + scheduledId[it]
            it++
            if(it === scheduledId.length)
            {
                it = 0
            }
        }
    }
    Rectangle {
        id: cotainer
        anchors.fill: parent
        color: "orange"
        Text {
            id: attention
            color: "black"
            font.pixelSize: 20
            text: "Please press Pause button first !"
            font.bold: true
            anchors.bottom: buttons.top
            anchors.horizontalCenter: buttons.horizontalCenter
            anchors.bottomMargin: 10
            visible: false
        }
        Text {
            id: processSelected
            color: "black"
            font.pixelSize: 20
            font.bold: true
            anchors.top: parent.top
            anchors.topMargin: 25
            anchors.horizontalCenter: parent.horizontalCenter
        }
        Row {
            id: buttons
            anchors.bottom: parent.bottom
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottomMargin: 50
            spacing: 5
            property int itr: 0
            Rectangle {
                id: back_rec
                height: 50
                width: 50
                color: "white"
                radius: width/2
                anchors.verticalCenter: parent.verticalCenter
                border.color: "black"
                border.width: 2
                Image {
                    id: back
                    source: "images/icons/play_forward.png"
                    anchors.fill: parent
                    mirror: true
                    mipmap: true
                    scale: 0.5
                    MouseArea {
                        anchors.fill: parent
                        acceptedButtons: Qt.LeftButton
                        hoverEnabled: true
                        onEntered: {
                            back_rec.color = "#001bc4"
                        }
                        onExited: {
                            back_rec.color = "white"
                        }
                        onClicked: {
                            if(!play_rec.played)
                            {
                                if(buttons.itr > 0)
                                {
                                    attention.visible = false
                                    process.stateDefault(buttons.itr)
                                    buttons.itr--
                                    process.stateFaded(buttons.itr)
                                    processSelected.text = "Current Process is : " + process.scheduledId[buttons.itr]
                                }
                                else
                                {
                                    attention.visible = false
                                    process.stateDefault(0)
                                    buttons.itr = process.scheduledId.length - 1
                                    process.stateFaded(buttons.itr)
                                    processSelected.text = "Current Process is : " + process.scheduledId[buttons.itr]
                                }
                            }
                            else
                            {
                                attention.visible = true
                            }
                        }
                    }
                }
            }
            Rectangle {
                id: play_rec
                height: 60
                width: 60
                color: "white"
                anchors.verticalCenter: parent.verticalCenter
                radius: width/2
                border.color: "black"
                border.width: 2
                property bool played: false
                Image {
                    id: play
                    source: "images/icons/play.png"
                    anchors.fill: parent
                    mipmap: true
                    scale: 0.5
                    MouseArea {
                        anchors.fill: parent
                        acceptedButtons: Qt.LeftButton
                        hoverEnabled: true
                        onEntered: {
                            play_rec.color = "#001bc4"
                        }
                        onExited: {
                            play_rec.color = "white"
                        }
                        onClicked: {
                            if(play_rec.played)
                            {
                                play.source = "images/icons/play.png"
                                drawTimer.stop()
                                buttons.itr = drawTimer.it - 1
                                play_rec.played = false
                                attention.visible = false
                            }
                            else
                            {
                                play.source = "images/icons/pause.png"
                                drawTimer.start()
                                play_rec.played = true
                            }
                        }
                    }
                }
            }
            Rectangle {
                id: front_rec
                height: 50
                width: 50
                color: "white"
                anchors.verticalCenter: parent.verticalCenter
                radius: width/2
                border.color: "black"
                border.width: 2
                Image {
                    id: front
                    source: "images/icons/play_forward.png"
                    anchors.fill: parent
                    mipmap: true
                    scale: 0.5
                    MouseArea {
                        anchors.fill: parent
                        acceptedButtons: Qt.LeftButton
                        hoverEnabled: true
                        onEntered: {
                            front_rec.color = "#001bc4"
                        }
                        onExited: {
                            front_rec.color = "white"
                        }
                        onClicked: {
                            if(!play_rec.played)
                            {
                                if(buttons.itr < process.scheduledId.length - 1 && buttons.itr >= 0)
                                {
                                    attention.visible = false
                                    process.stateDefault(buttons.itr)
                                    buttons.itr++
                                    process.stateFaded(buttons.itr)
                                    processSelected.text = "Current Process is : " + process.scheduledId[buttons.itr]
                                }
                                else
                                {
                                    attention.visible = false
                                    process.stateDefault(process.scheduledId.length - 1)
                                    buttons.itr = 0
                                    process.stateFaded(buttons.itr)
                                    processSelected.text = "Current Process is : " + process.scheduledId[buttons.itr]
                                }
                            }
                            else
                            {
                                attention.visible = true
                            }
                        }
                    }
                }
            }
        }
        ScrollView{
            width: parent.width*0.9
            height: 100
            anchors.centerIn: parent
            clip: true
            Row{
                id: rowId
                anchors.centerIn: parent
                antialiasing: true
                Repeater{
                    id: processRepeater
                    signal widthAlarm()
                    function setProcesses()
                    {
                        for(var i = 0 ; i < model.length; i++)
                        {
                            widthAlarm()
                            itemAt(i).setTexts()
                        }
                    }
                    Rectangle{
                        id: processRect
                        height: 70
                        color: "#001bc4"
                        border.color: "white"
                        radius: 10
                        function setWidth()
                        {
                            if(index == 0)
                            {
                                width = process.ganttChart[index]*process.width*0.08
                            }
                            else
                            {
                                width =  (process.ganttChart[index] - process.ganttChart[index-1])*process.width*0.08
                            }
                        }
                        function setTexts()
                        {
                            textIdLable.text = process.scheduledId[index]
                            textIdBurstTime.text = process.ganttChart[index]
                        }
                        Connections {
                            target: processRepeater
                            onWidthAlarm: {
                                processRect.setWidth()
                            }
                        }
                        states: [
                            State {
                                name: "faded"
                                PropertyChanges {
                                    target: processRect
                                    color: "gray"
                                }
                            },
                            State {
                                name: "original"
                                PropertyChanges {
                                    target: processRect
                                    color: "#001bc4"
                                }
                            }
                        ]
                        transitions: Transition {
                            ColorAnimation {
                                duration: 500
                            }
                        }
                        Text {
                            id: zeros
                            text: "0"
                            color: "black"
                            font.pixelSize: 16
                            visible: index == 0 ? true : false
                            font.family: "Helvetica"
                            font.bold: true
                            anchors.top: processRect.bottom
                            anchors.left: processRect.left
                        }
                        Text {
                            id: textIdLable
                            color: "white"
                            font.pixelSize: process.width*0.015
                            font.bold: true
                            anchors.centerIn: parent
                        }
                        Text{
                            id: textIdBurstTime
                            color: "black"
                            font.pixelSize: 16
                            font.family: "Helvetica"
                            font.bold: true
                            anchors.top: processRect.bottom
                            anchors.right: processRect.right
                        }
                    }
                }
            }
        }
    }
}
