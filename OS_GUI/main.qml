import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts 1.3
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4

Window {
    id: gui
    visible: true
    width: 800
    height: 600
    title: qsTr("OS GUI")
    color: "black"

    property var processName: []
    property var arrivalTime: []
    property var burstTime: []
    property var priority: []

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
            color: "orange"
        }
        Text {
            text: "Number of process: "
            font.bold: true
            font.family: "Comic Sans MS"
            Layout.row: 1
            Layout.column: 0
            color: "orange"
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
                id_table.visible= true
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
            color: "orange"
        }
        Text {
            text: "Busrt Time: "
            font.bold: true
            font.family: "Comic Sans MS"
            Layout.row: 1
            Layout.column: 0
            color: "orange"
        }
        Text {
            text: "Arrival Time: "
            font.bold: true
            font.family: "Comic Sans MS"
            Layout.row: 2
            Layout.column: 0
            color: "orange"
        }
        Text {
            text: "Priority: "
            font.bold: true
            font.family: "Comic Sans MS"
            Layout.row: 3
            Layout.column: 0
            visible: processtype.currentText == "Priority" ? true : false
            color: "orange"
        }
        Text {
            id: warning
            text: "Please select a process !"
            font.bold: true
            font.family: "Comic Sans MS"
            Layout.row: 4
            Layout.column: 1
            visible: false
            color: "orange"
        }
        CustomizingComboBox {
            id: processnumbers
            model: processlist
            Layout.column: 1
            Layout.row: 0
            focus: true
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
                if(processnumbers.currentIndex >= 0)
                {
                    warning.visible = false
                    processdata.set(processnumbers.currentIndex,{"ProcessName":processnumbers.currentText,
                                        "ArrivalTime":arrivaltime.value,
                                        "BurstTime":bursttime.value,
                                        "Priority":priority.value,
                                        "Initial":"Inialized"})
                    gui.processName[processnumbers.currentIndex] = processnumbers.currentText
                    gui.arrivalTime[processnumbers.currentIndex] = arrivaltime.value
                    gui.burstTime[processnumbers.currentIndex] = bursttime.value
                    gui.priority[processnumbers.currentIndex] = priority.value
                }
                else
                {
                    warning.visible = true
                }
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
                                       "Priority":0,
                                       "Initial":"Not Inialized"})
            }
        }
    }
    TableView {
        id:id_table
        width: parent.width/2.5
        height: parent.height/2
        anchors.top: lastconfigration.bottom
        anchors.left: lastconfigration.left
        anchors.topMargin: parent.height/15
        focus: true
        model: processdata
        visible: false
        rowDelegate: Rectangle {
            height: textrow.implicitHeight * 1.2
            width: textrow.implicitWidth
            color: {
                if(processdata.get(styleData.row)["Initial"] === "Inialized")
                {
                    return "white"
                }
                else
                {
                    return "orange"
                }
            }
            border.color: "black"
            Text {
                id: textrow
                anchors.fill: parent
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: styleData.textAlignment
                anchors.leftMargin: 12
                text: styleData.value
                elide: Text.ElideRight
                color: "black"
                renderType: Text.NativeRendering
            }
            Rectangle {
                anchors.right: parent.right
                anchors.top: parent.top
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 1
                anchors.topMargin: 1
                width: 1
                color: "orange"
            }
        }
        headerDelegate: Rectangle {
            height: textItem.implicitHeight * 1.2
            width: textItem.implicitWidth
            color: "black"
            border.color: "orange"
            Text {
                id: textItem
                anchors.fill: parent
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: styleData.textAlignment
                anchors.leftMargin: 12
                text: styleData.value
                elide: Text.ElideRight
                color: "orange"
                renderType: Text.NativeRendering
            }
            Rectangle {
                anchors.right: parent.right
                anchors.top: parent.top
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 1
                anchors.topMargin: 1
                width: 1
                color: "black"
            }
        }
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
            visible: lastconfigration.processtype == "Priority" ? true : false
        }
        TableViewColumn{
            role: "Initial"
            title: "Initialization"
        }
    }
    CustomizingButton {
        id: scheduling
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 10
        anchors.horizontalCenter: processname.horizontalCenter
        text: "Start scheduling"
        visible: false
    }
    Rectangle{
        id: processname
        color: "black"
        width: parent.width/8
        height: parent.height/15
        anchors.right: ispreemptive.left
        anchors.verticalCenter: ispreemptive.verticalCenter
        radius: width/10
        border.color: "orange"
        border.width: 2
        visible: false
        Text {
            anchors.centerIn: parent
            text: "Type: " + lastconfigration.processtype
            font.pixelSize: parent.width*0.09
            color: "orange"
        }
    }
    Rectangle{
        id: noofprocess
        color: "black"
        width: parent.width/8
        height: parent.height/15
        anchors.right: processname.left
        anchors.verticalCenter: ispreemptive.verticalCenter
        radius: width/10
        border.color: "orange"
        border.width: 2
        visible: false
        Text {
            anchors.centerIn: parent
            text: "Number of process: " + lastconfigration.processnumber
            font.pixelSize: parent.width*0.09
            color: "orange"
        }
    }
    Rectangle{
        id: ispreemptive
        color: "black"
        width: parent.width/8
        height: parent.height/15
        anchors.right: parent.right
        anchors.rightMargin: 20
        anchors.bottom: scheduling.bottom
        anchors.bottomMargin: 100
        radius: width/10
        border.color: "orange"
        border.width: 2
        visible: false
        Text {
            anchors.centerIn: parent
            text: lastconfigration.ispreemptive ? "Preemptive" : "Non-Preemptive"
            font.pixelSize: parent.width*0.1
            color: "orange"
        }
    }
}
