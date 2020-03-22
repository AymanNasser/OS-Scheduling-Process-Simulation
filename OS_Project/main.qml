import QtQuick 2.11
import QtQuick.Window 2.11
import QtQuick.Controls 2.4
// This is available in all editors.


Window {
    // Window Proprties
    id: root
    visible: true
    width: 500
    height: 500
    title: qsTr("Simulation")
    color: "white"


    Simulation{
        processNum: 3
        anchors.centerIn: parent
        burstTime: [2,8,3]
        arrivalTime: [0,2,1]
        //processPriority: [0,2,1]
     }



//    Rectangle{
//     id:rec1
//     width: 100
//     radius: 20
//     height: 100
//     antialiasing: true
//     color: "lightblue"

//     NumberAnimation on x{
//         to: root.height
//         duration: 5000
//     }
//     NumberAnimation on y{
//         to: root.width
//         duration: 5000
//     }

//     NumberAnimation on rotation {
//        from: 0
//        to: -180
//        duration: 1000
//        loops: Animation.Infinite

//     }


//     ColorAnimation on color{
//         from: "white"
//         to: "black"
//         duration: 20000
//     }

//    }



}




