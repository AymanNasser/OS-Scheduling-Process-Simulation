import QtQuick 2.11
import QtQuick.Window 2.11

Window {
    id: root
    visible: true
    width: 800
    height: 600
    minimumHeight: 600
    minimumWidth: 800
    title: qsTr("Simulation")
    Item {
        anchors.fill: parent
        Simulation{
            id: simulator
            anchors.fill: parent
            objectName: "SimulationLists"
            onWidthChanged: {
                setModel()
            }
        }
    }
}
