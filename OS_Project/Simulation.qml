import QtQuick 2.11
import QtQuick.Window 2.11
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4

Item {
    id: process
    property int processNum
    property int maxArrivalTime
    property string algoType
    property var processPriority: []
    property var arrivalTime: []
    property var burstTime: []

    function find(model, e) {
      for(var i = 0; i < processNum; ++i){
        if (model[i] === e)
            return i;
      }
      return null
    }


    function getMaxTime(model){
        for(var i = 0; i < processNum; ++i){
          if (model[i] > maxArrivalTime)
              maxArrivalTime = model[i];
        }
    }



    Timer{
        id: timerId
        repeat: true
        interval: 2000
        property int i: 0
        running: true
        onTriggered: {

//            rowId.accumulatedTime += burstTime[i]
//             processRepeater.itemAt(i).visible = true ;

         i++;
         i == processNum ? timerId.running = false: timerId.running = true ;
        }
    }


    Timer{
        id: drawTimer
        repeat: true
        interval: 1800
        property int it: 0
        running: true
        onTriggered: {
            var x = find(arrivalTime,it);
            //console.log(x);
            it < 1 ? getMaxTime(arrivalTime) : it = it;
            console.log(maxArrivalTime);


            if(x !== null) processRepeater.itemAt(x).visible = true


            it++;
            it <= maxArrivalTime ?drawTimer.running = true : drawTimer.running = false  ;
        }


    }

    Row{
        id: rowId
        anchors.centerIn: parent
        antialiasing: true
        property int accumulatedTime: 0

        Repeater{
            id: processRepeater
            model: arrivalTime

            function drawBasedOnAlgorithm(){
                if(process.algoType == "FCFS"){

                }
                else if(process.algoType == "SJF"){

                }
                else if(process.algoType == "RR"){

                }

            }

            Rectangle{
                id: processRect
                //anchors.left: index != 0 ? processRepeater.itemAt(index-1).right: parent.left
                width: burstTime[index]*100
                height: 70
                color: "steelblue"
                border.color: "white"
                radius: 10
                antialiasing: true
                visible: false


                Text {
                    id: textIdLable
                    text: qsTr("P" + modelData)
                    antialiasing: true
                    color: "yellow"
                    font.pixelSize: 20
                    font.bold: true
                    anchors.centerIn: parent
                }

//                Text{
//                    id: textIdBurstTime

//                    text: (index == 0) ? "0" : rowId.accumulatedTime
//                    antialiasing: true
//                    color: "black"
//                    font.pixelSize: 16
//                    font.bold: true
//                    anchors.top: processRect.bottom
//                    anchors.left: processRect.left
//                }


            }

            }
        }



}


