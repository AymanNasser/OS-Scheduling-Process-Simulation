import QtQuick 2.11
import QtQuick.Window 2.11
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4

Item {
    id: process
    anchors.centerIn: parent
    property var scheduledId: []
    property var ganttChart: []
    property var waitingTime: []


    Timer{
        id: drawTimer
        repeat: true
        interval: 600
        property int it: 0
        running: true
        onTriggered: {
        processRepeater.itemAt(it).visible = true;
        it++;
        it == scheduledId.length ? drawTimer.running = false: drawTimer.running = true ;
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

                width: 100
                height: 70
                color: "steelblue"
                border.color: "white"
                radius: 10
                antialiasing: true
                visible: true

                Text {
                    id: textIdLable
                    text: scheduledId[index]
                    antialiasing: true
                    color: "yellow"
                    font.pixelSize: 20
                    font.bold: true
                    anchors.centerIn: parent
                }

                Text{
                    id: textIdBurstTime

                    text: ganttChart[index]
                    antialiasing: true
                    color: "black"
                    font.pixelSize: 16
                    leftPadding: 87

                    font.family: "Helvetica"
                    font.bold: true
                    anchors.top: processRect.bottom
                    anchors.left: processRect.left
                }



            }


            }

        }



}


