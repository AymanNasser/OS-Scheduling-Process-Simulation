import QtQuick 2.11
import QtQuick.Window 2.11
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import QtQuick.Layouts 1.3
import QList 1.0

Item {
    id: process
    property var scheduledId
    property var ganttChart
    property var waitingTime
    signal dataIsLoaded()
    function setLists(list_id,list_time)
    {
        simulator_lists.setIDs(list_id)
        simulator_lists.setTimes(list_time)
        scheduledId = simulator_lists.ProcessID
        ganttChart = simulator_lists.ProcessTime
        dataIsLoaded()
        console.log(scheduledId[0],scheduledId.length,ganttChart.length)
    }
    function stateFaded(index)
    {
        processRepeater.itemAt(index).state = "faded"
        drawTimer.it = index
        console.log(drawTimer.it)
    }
    function stateDefault(index)
    {
        processRepeater.itemAt(index).state = "original"
    }

    Timer{
        id: drawTimer
        repeat: true
        interval: 1000
        property int it: 0
        running: true
        onTriggered: {
            if(it != 0)
            {
                processRepeater.itemAt(it-1).state = "original"
            }
            processRepeater.itemAt(it).state = "faded"
            it++
            it == scheduledId.length ? drawTimer.running = false: drawTimer.running = true
        }
    }
    ListQML {
        id: simulator_lists
    }
    Rectangle {
        id: cotainer
        anchors.fill: parent
        color: "orange"
        Row {
            id: buttons
            anchors.bottom: parent.bottom
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottomMargin: 50
            property int itr
            Rectangle {
                id: back_rec
                height: 40
                width: 40
                color: "dark blue"
                radius: width/2
                anchors.verticalCenter: parent.verticalCenter
                border.color: "black"
                border.width: 2
                Image {
                    id: back
                    source: "images/icons/user-male.png"
                    anchors.fill: parent
                    mipmap: true
                    MouseArea {
                        anchors.fill: parent
                        acceptedButtons: Qt.LeftButton
                        hoverEnabled: true
                        onEntered: {
                            back_rec.width = 65
                            back_rec.height = 65
                        }
                        onExited: {
                            back_rec.width = 40
                            back_rec.height = 40
                        }
                        onClicked: {
                            if(buttons.itr != 0 && !play_rec.played)
                            {
                                process.stateDefault(buttons.itr)
                                buttons.itr--
                                process.stateFaded(buttons.itr)
                            }
                        }
                    }
                }
            }
            Rectangle {
                id: play_rec
                height: 50
                width: 50
                color: "dark blue"
                anchors.verticalCenter: parent.verticalCenter
                radius: width/2
                border.color: "black"
                border.width: 2
                property bool played: true
                Image {
                    id: play
                    source: "images/icons/comp.png"
                    anchors.fill: parent
                    mipmap: true
                    MouseArea {
                        anchors.fill: parent
                        acceptedButtons: Qt.LeftButton
                        hoverEnabled: true
                        onEntered: {
                            play_rec.width = 75
                            play_rec.height = 75
                        }
                        onExited: {
                            play_rec.width = 50
                            play_rec.height = 50
                        }
                        onClicked: {
                            if(play_rec.played)
                            {
                                drawTimer.stop()
                                buttons.itr = drawTimer.it - 1
                                play_rec.played = false
                            }
                            else
                            {
                                drawTimer.start()
                                play_rec.played = true
                            }
                        }
                    }
                }
            }
            Rectangle {
                id: front_rec
                height: 40
                width: 40
                color: "dark blue"
                anchors.verticalCenter: parent.verticalCenter
                radius: width/2
                border.color: "black"
                border.width: 2
                Image {
                    id: front
                    source: "images/icons/comp.png"
                    anchors.fill: parent
                    mipmap: true
                    MouseArea {
                        anchors.fill: parent
                        acceptedButtons: Qt.LeftButton
                        hoverEnabled: true
                        onEntered: {
                            front_rec.width = 65
                            front_rec.height = 65
                        }
                        onExited: {
                            front_rec.width = 40
                            front_rec.height = 40
                        }
                        onClicked: {
                            if(buttons.itr != process.scheduledId.length - 1 && !play_rec.played)
                            {
                                process.stateDefault(buttons.itr)
                                buttons.itr++
                                process.stateFaded(buttons.itr)
                            }
                        }
                    }
                }
            }
        }


        Row{
            id: rowId
            anchors.centerIn: parent
            antialiasing: true

            Repeater{
                id: processRepeater
                model: process.scheduledId


                Rectangle{
                    id: processRect

                    width: index != 0 ? (ganttChart[index] - ganttChart[index-1])*process.width*0.08 :
                                        (ganttChart[index+1]- ganttChart[index]) *process.width*0.08
                    height: 70
                    color: "steelblue"
                    border.color: "white"
                    radius: 10
                    antialiasing: true
                    visible: true

                    states: [
                        State {
                            name: "faded"

                            PropertyChanges {
                                target: processRect
                                color: "black"
                            }
                        },
                        State {
                            name: "original"
                            PropertyChanges {
                                target: processRect
                                color: "steelblue"
                            }
                        }
                    ]
                    transitions: Transition {
                        ParallelAnimation{
                            ColorAnimation {
                                duration: drawTimer.interval
                            }
                        }
                    }

                    Text {
                        id: zeros
                        text: "0"
                        antialiasing: true
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
                        text: scheduledId[index]
                        antialiasing: true
                        color: "white"
                        font.pixelSize: process.width*0.015
                        font.bold: true
                        anchors.centerIn: parent
                    }

                    Text{
                        id: textIdBurstTime

                        text: ganttChart[index]
                        antialiasing: true
                        color: "black"
                        font.pixelSize: 16
                        font.family: "Helvetica"
                        font.bold: true
                        anchors.top: processRect.bottom
                        anchors.left: processRect.right
                    }

                }

            }

        }
    }

    //    ToolBar{
    //        id: movingToolBar
    //        property int itr
    //        style: ToolBarStyle {
    //            background: Rectangle {
    //                implicitWidth: 100
    //                implicitHeight: 40
    //                border.color: "#999"
    //                gradient: Gradient {
    //                    GradientStop { position: 0 ; color: "#fff" }
    //                    GradientStop { position: 1 ; color: "#eee" }
    //                }
    //            }
    //        }
    //        RowLayout {
    //            anchors.top: processRepeater.bottom
    //            anchors.topMargin: 20
    //            ToolButton{
    //                id: stop

    //                text: "Stop"

    //                onClicked: {
    //                    movingToolBar.itr= drawTimer.it; drawTimer.stop();
    //                }
    //            }

    //            ToolButton{
    //                id: back
    //                anchors.left: stop.right
    //                text: "Back"
    //                //iconSource:   "~/Pictures/user-male.png"

    //                onClicked: {
    //                    processRepeater.itemAt(movingToolBar.itr-1).state = "original"
    //                    movingToolBar.itr--;

    //                }
    //            }

    //            ToolButton{
    //                id: front
    //                anchors.left: back.right
    //                text: "Front"
    //                //iconSource: "user-male.png"
    //                onClicked: {
    //                    movingToolBar.itr
    //                    processRepeater.itemAt(movingToolBar.itr).state = "faded"
    //                    movingToolBar.itr++
    //                }
    //            }

    //        }

    //    }

}
