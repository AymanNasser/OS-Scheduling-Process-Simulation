import QtQuick 2.12
import QtQuick.Window 2.12

// This is available in all editors.


Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Simulation")

    Row{
        y:0
        antialiasing: true
        Repeater{
            property int  processId
            model: 5
            Rectangle{
                anchors.left: processId.anchors.right
                width: 100
                height: 100
                color: "red"
                border.color: "white"
                antialiasing: true

                Text {
                    id: textIdLable
                    text: qsTr("x")
                    antialiasing: true
                    anchors.centerIn: parent
                    color: "yellow"
                }
            }

            }
        }
    }




