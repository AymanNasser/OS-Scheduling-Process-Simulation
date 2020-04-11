import QtQuick 2.11
import QtQuick.Window 2.11
import QtQuick.Controls 2.4
// This is available in all editors.

Window {
    // Window Proprties
    id: root
    visible: true
    width: 1000
    height: 1000
    title: qsTr("Simulation")

    Item {
        width: 200; height: 200

        Loader {
            // Explicitly set the size of the
            // Loader to the parent item's size
            id: loading_simulation
            anchors.centerIn: parent
            //sourceComponent: rect
        }
    }
    Component {
        id: rect
        Rectangle {
            width: 50
            height: 50
            color: "red"
        }
    }
    Simulation{
        id: simulator
        scheduledId:["IDEAL","P0","P0","P1","P0","P2","P3","P4","P3","P5","P6","P9","P12"]
        ganttChart: [1,2,3,4,5,6,7,9,11,15,19,21,25]
        anchors.fill: parent
        onDataIsLoaded: {
            loading_simulation.sourceComponent = rect
        }
    }

}
