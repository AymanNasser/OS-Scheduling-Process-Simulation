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
        scheduledId: simulator_lists.readIDs()//["IDEAL","P0","P0","P1","P0","P2","P3","P4","P3"]
        ganttChart: simulator_lists.ProcessTime//[1,2,3,4,5,6,7,9,11]
        Component.onCompleted: {
           for(var i ; i < scheduledId.length;i++)
           {
               console.log(scheduledId[i],ganttChart[i])
           }
           for(var j ; j < simulator_lists.ProcessID.length;j++)
           {
               console.log(simulator_lists.ProcessID[j],simulator_lists.ProcessTime[j])
           }
        }
        width: parent.width
    }
}




