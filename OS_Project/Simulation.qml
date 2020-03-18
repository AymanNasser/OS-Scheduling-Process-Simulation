import QtQuick 2.0

Item {
    id: process
    property int processNum
    property string algoType
    property ListModel processPriority: processNum
    property ListModel arrivalTime: processNum

    Timer{
        id: timerId
        repeat: true
        interval: 1000
        running: true
        onTriggered:{


        }
    }

    Row{
        id: rowId
        //anchors.centerIn: window
        antialiasing: true

        Repeater{
            id: processDraw
            model: process.processNum
            Rectangle{
                width: 100
                height: 100
                color: "steelblue"
                border.color: "white"
                radius: 10
                antialiasing: true
                Text {
                    id: textIdLable
                    text: qsTr("P" + index)
                    antialiasing: true
                    color: "yellow"
                    font.pixelSize: 10
                    font.bold: true
                    anchors.centerIn: parent
                }

            }

            }
        }

}
