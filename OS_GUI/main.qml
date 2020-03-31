import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts 1.3
import QtQuick.Controls 1.4

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("OS GUI")
    property var processmap: {{}}
    ListModel {
        id: processlist
    }
    GridLayout {
        id: basicsconfigration
        anchors.left: parent.left
        anchors.top: parent.top
        anchors.topMargin: parent.height*0.1
        anchors.leftMargin: parent.width*0.1
        columns: 2
        rows: 5
        columnSpacing: 20
        rowSpacing: 10
        Text {
            text: "Process Type: "
            font.bold: true
            font.family: "Comic Sans MS"
            Layout.row: 0
            Layout.column: 0
        }
        Text {
            text: "Number of process: "
            font.bold: true
            font.family: "Comic Sans MS"
            Layout.row: 1
            Layout.column: 0
        }
        CustomizingComboBox {
            id: processtype
            model: ["FCFS","Priority","Round Robin","SJF"]
            Layout.column: 1
            Layout.row: 0
            onCurrentTextChanged: {
                if(currentText == "Priority" || currentText == "SJF")
                {
                    preemptive.visible = true
                    nonpreemptive.visible = true
                }
                else
                {
                    preemptive.visible = false
                    nonpreemptive.visible = false
                }
            }
        }
        CustomizingSpinBox {
            id: processnumber
            Layout.column: 1
            Layout.row: 1
        }
        CustomizingRadioButton {
            id: preemptive
            text: "Preemptive"
            Layout.column: 0
            Layout.row: 2
            visible: false
        }
        CustomizingRadioButton {
            id: nonpreemptive
            text: "Non-Preemptive"
            Layout.column: 0
            Layout.row: 3
            checked: true
            visible: false
        }
        CustomizingButton {
            id: submitbasics
            text: "Submit"
            Layout.column: 0
            Layout.row: 4
            onClicked: {
                basicsconfigration.visible = false
                lastconfigration.visible = true
                lastconfigration.processtype = processtype.currentText
                lastconfigration.processnumber = processnumber.value
                lastconfigration.ispreemptive = preemptive.checked ? true : false
                for(var i = 0;i < processnumber.value;i++)
                {
                    processlist.append({"name":"P"+i})
                }
                processdata.initialzieList()
                scheduling.visible = true
                processname.visible = true
                noofprocess.visible = true
                if(processtype.currentText == "Priority" || processtype.currentText == "SJF")
                {
                    ispreemptive.visible = true
                }
            }
        }
    }
    GridLayout {
        id: lastconfigration
        anchors.left: parent.left
        anchors.top: parent.top
        anchors.topMargin: parent.height*0.1
        anchors.leftMargin: parent.width*0.1
        columns: 2
        rows: 5
        columnSpacing: 20
        rowSpacing: 10
        visible: false
        property string processtype: "NULL"
        property int processnumber: 0
        property bool ispreemptive: false
        Text {
            text: "Process No. : "
            font.bold: true
            font.family: "Comic Sans MS"
            Layout.row: 0
            Layout.column: 0
        }
        Text {
            text: "Busrt Time: "
            font.bold: true
            font.family: "Comic Sans MS"
            Layout.row: 1
            Layout.column: 0
        }
        Text {
            text: "Arrival Time: "
            font.bold: true
            font.family: "Comic Sans MS"
            Layout.row: 2
            Layout.column: 0
        }
        Text {
            text: "Priority: "
            font.bold: true
            font.family: "Comic Sans MS"
            Layout.row: 3
            Layout.column: 0
            visible: processtype.currentText == "Priority" ? true : false
        }
        CustomizingComboBox {
            id: processnumbers
            model: processlist
            Layout.column: 1
            Layout.row: 0
        }
        CustomizingSpinBox {
            id: bursttime
            Layout.column: 1
            Layout.row: 1
        }
        CustomizingSpinBox {
            id: arrivaltime
            Layout.column: 1
            Layout.row: 2
        }
        CustomizingSpinBox {
            id: priority
            Layout.column: 1
            Layout.row: 3
            visible: processtype.currentText == "Priority" ? true : false
        }
        CustomizingButton {
            id: submitconfig
            text: "Submit Process"
            Layout.column: 0
            Layout.row: 4
            onClicked: {
                processdata.set(processnumbers.currentIndex,{"ProcessName":processnumbers.currentText,
                                    "ArrivalTime":arrivaltime.value,
                                    "BurstTime":bursttime.value,
                                    "Priority":priority.value})

            }
        }
    }
    ListModel {
        id: processdata
        function initialzieList() {
            for(var i = 0;i<lastconfigration.processnumber;i++)
            {
                processdata.append({"ProcessName":"P"+i,
                                    "ArrivalTime":0,
                                    "BurstTime":0,
                                    "Priority":0})
            }
        }
    }
    TableView {
        id:id_table
        width: parent.width/2
        height: parent.height/2
        anchors.left: lastconfigration.right
        anchors.leftMargin: 100
        focus: true
        model: processdata
        TableViewColumn {
            role: "ProcessName"
            title: "Process"
        }
        TableViewColumn{
            role: "ArrivalTime"
            title: "Arrival Time"
        }
        TableViewColumn{
            role: "BurstTime"
            title: "Burst Time"
        }
        TableViewColumn{
            role: "Priority"
            title: "Priority"
        }
    }
    CustomizingButton {
        id: scheduling
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 10
        anchors.horizontalCenter: parent.horizontalCenter
        text: "Start scheduling"
        visible: false
        onClicked: {

        }
    }
    Rectangle{
        id: processname
        color: "black"
        width: 200
        height: 50
        anchors.bottom: scheduling.bottom
        anchors.bottomMargin: 100
        anchors.horizontalCenter: parent.horizontalCenter
        radius: width/10
        border.color: "orange"
        border.width: 2
        visible: false
        Text {
            anchors.centerIn: parent
            text: "Process Type: " + lastconfigration.processtype
            color: "orange"
        }
    }
    Rectangle{
        id: noofprocess
        color: "black"
        width: 200
        height: 50
        anchors.right: processname.left
        anchors.verticalCenter: processname.verticalCenter
        radius: width/10
        border.color: "orange"
        border.width: 2
        visible: false
        Text {
            anchors.centerIn: parent
            text: "Number of process: " + lastconfigration.processnumber
            color: "orange"
        }
    }
    Rectangle{
        id: ispreemptive
        color: "black"
        width: 200
        height: 50
        anchors.left: processname.right
        anchors.verticalCenter: processname.verticalCenter
        radius: width/10
        border.color: "orange"
        border.width: 2
        visible: false
        Text {
            anchors.centerIn: parent
            text: lastconfigration.ispreemptive ? "Preemptive" : "Non-Preemptive"
            color: "orange"
        }
    }
}
