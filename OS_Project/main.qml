import QtQuick 2.12
import QtQuick.Window 2.12

// This is available in all editors.


Window {
    // Window Proprties
    visible: true
    width: 640
    height: 480
    title: qsTr("Simulation")

    Simulation{
    processNum: 5
    algoType: "SJF"
    }

}




