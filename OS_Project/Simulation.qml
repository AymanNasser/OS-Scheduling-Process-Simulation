import QtQuick 2.11
import QtQuick.Window 2.11
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4

Item {
    id: process
    anchors.centerIn: parent
    property var scheduledId
    property var ganttChart
    property var waitingTime

    Timer{
        id: drawTimer
        repeat: true
        interval: 2000
        property int it: 0
        running: true
        onTriggered: {

            //processRepeater.itemAt(it).visible = true
            processRepeater.itemAt(it).state = "faded"
            it++;
            it == scheduledId.length ? drawTimer.running = false: drawTimer.running = true ;
        }
    }


    //    ToolBar{
    //        id: movingToolBar
    //        property int itr

    ////        style: ToolBarStyle {
    ////                background: Rectangle {
    ////                    implicitWidth: 100
    ////                    implicitHeight: 40
    ////                    border.color: "#999"
    ////                    gradient: Gradient {
    ////                        GradientStop { position: 0 ; color: "#fff" }
    ////                        GradientStop { position: 1 ; color: "#eee" }
    ////                    }
    ////                }
    ////            }
    //        ToolButton{
    //            id: stop

    //            text: "Stop"

    //            onClicked: {
    //                movingToolBar.itr= drawTimer.it; drawTimer.stop();
    //            }
    //        }

    //        ToolButton{
    //            id: back
    //            anchors.left: stop.right
    //            text: "Back"
    //            iconSource:   "~/Pictures/user-male.png"

    //            onClicked: {
    //                processRepeater.itemAt(movingToolBar.itr-1).state = "original"
    //                movingToolBar.itr--;

    //            }
    //        }

    //        ToolButton{
    //            id: front
    //            anchors.left: back.right
    //            text: "Front"
    //            //iconSource: "user-male.png"
    //            onClicked: {
    //                movingToolBar.itr
    //                processRepeater.itemAt(movingToolBar.itr).state = "faded"
    //                movingToolBar.itr++
    //            }
    //        }

    //    }

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


