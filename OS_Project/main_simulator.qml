import QtQuick 2.11
import QtQuick.Window 2.11
import QtQuick.Controls 2.4
import QList 1.0
// This is available in all editors.


Window {
    // Window Proprties
    id: root
    visible: true
    width: 1000
    height: 1000
    title: qsTr("Simulation")
    color: "white"
    ListQML {
        id: simulator_lists
    }

    Simulation{
    scheduledId: ["IDEAL","P0","P0","P1","P0","P2","P3","P4","P3"]
    ganttChart: [1,2,3,4,5,6,7,9,11]
//        Component.onCompleted: {
//            scheduledId = simulator_lists.ProcessID
//            ganttChart = simulator_lists.ProcessTime
//        }

    width: parent.width

    }


}




