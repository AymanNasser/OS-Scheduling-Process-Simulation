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
    function setLists(list_id,list_time)
    {
        simulator_lists.setIDs(list_id)
        simulator_lists.setTimes(list_time)
        simulator.scheduledId = simulator_lists.ProcessID
        simulator.ganttChart = simulator_lists.ProcessTime
        console.log(simulator.scheduledId[0],simulator.scheduledId.length,simulator.ganttChart.length)
    }
    ListQML {
        id: simulator_lists
//        Component.onCompleted: {
//            simulator.scheduledId = ProcessID
//            console.log("hello",ProcessID.length,ProcessID[0],simulator.scheduledId[0])
//            for(var i = 0 ; i < idsLength();i++)
//            {
//                simulator.scheduledId.push(readIDitem(i))
//                simulator.ganttChart.push(readTimeitem(i))
//            }
//        }
    }
    Simulation{
        id: simulator
        //scheduledId: simulator_lists.ProcessID//["IDEAL","P0","P0","P1","P0","P2","P3","P4","P3"]
        //ganttChart: simulator_lists.ProcessTime//[1,2,3,4,5,6,7,9,11]
        width: parent.width
    }
}




