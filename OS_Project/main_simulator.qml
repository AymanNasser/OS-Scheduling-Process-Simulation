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
    color: "white"

    Simulation{
    scheduledId: ["IDEAL","P0","P0","P1","P0","P2","P3","P4","P3"]
    ganttChart: [1,2,3,4,5,6,7,9,11]
    width: parent.width

    }


}




