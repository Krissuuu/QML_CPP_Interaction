import QtQuick 2.15
import QtQuick.Window 2.15

import QtQuick.Controls 2.14

import kris 1.0

Window {
    id: root
    width: 640
    height: 480
    visible: true
    color : "black"
    title: qsTr("Hello World")

    property string msg_name: "Kris.Su"
    property int msg_age: 25

    property int qmlcount: 0

    signal qmlSendMsg(string arg1, int arg2)

    Kris_cppObj {
        id: kris_cppObj
        onPropertyChanged: {
            console.log("C++'s Signal / onPropertyChanged", property_)
        }
        onCppSendMsg: {
           console.log("C++'s Signal / onCppSendMsg")
        }
    }

    Button {
        id: signal_slot_test
        text: "Signal / Slot test"
        width: 200
        height: 40
        onClicked: {
            // Signal / Slot test
            root.qmlSendMsg(msg_name, msg_age)
        }
    }

    Button {
        id: q_INVOKABLE_test
        text: "Q_INVOKABLE test"
        anchors.top: signal_slot_test.bottom
        anchors.margins: 10
        width: 200
        height: 40
        onClicked: {
            // Q_INVOKABLE test
            qmlcount += 1
            var return_val = kris_cppObj.cpp_method(qmlcount)
            console.log("cpp_method", return_val)
        }
    }

    Button {
        id: q_PROPERTY_test
        text: "Q_PROPERTY test"
        anchors.top: q_INVOKABLE_test.bottom
        anchors.margins: 10
        width: 200
        height: 40
        onClicked: {
            // Q_PROPERTY test
            kris_cppObj.property_ = 1234
        }
    }

    Button {
        text: "Other"
        anchors.top: q_PROPERTY_test.bottom
        anchors.margins: 10
        width: 200
        height: 40
        onClicked: {
            // Other
            kris_cppObj.cppSendMsg("Kris", 7890)
//            kris_cppObj.cppRecvMsg("Kris", 7890)
//            kris_cppObj.propertyChanged()
        }
    }

    // Signal / Slot test
    function qmlRecvMsg(arg1, arg2){
        console.log("qml slot runing", arg1, arg2)
    }

    // Signal / Slot test
    Component.onCompleted: {
        root.qmlSendMsg.connect(kris_cppObj.cppRecvMsg)
        kris_cppObj.cppSendMsg.connect(root.qmlRecvMsg)
        console.log("onCompleted")
    }
}
