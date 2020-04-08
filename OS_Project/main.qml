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
    scheduledId: ["ideal","P0","P0","P1","P0","P2","P3","P4","P3"]
    ganttChart: [1,2,3,4,5,6,7,9,11]
    width: parent.width
    anchors.horizontalCenter: root.horizontalCenter
    anchors.verticalCenter:  root.bottom
    }








//    function draw(idd){
//        idd.sourceComponent = rect
//        idd.active = true
//    }

//    Timer{
//           id: timerId
//           repeat: true
//           interval: 1000
//           property int i: 0
//           running: true
//           onTriggered: {
//           // draw(load)
//             rep.itemAt(i).sourceComponent = rect
//            i++

//           }
//       }
//    Repeater
//    {
//     id: rep
//     model: 4
//     anchors.centerIn: parent
//       Loader{
//           id: load
//           anchors.centerIn: parent


//           //sourceComponent: rect

//       }
//    }

//        Row{
//            id: re
//            anchors.centerIn: parent
//           Component {
//                id: rect
//                    Rectangle {
//                        anchors.left: root.right
//                        anchors.bottom: root.bottom

//                        width: 100
//                        height: 150
//                        color:"blue"
//                    }
//                }
//    }





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




