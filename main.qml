import QtQuick 2.5
import QtQuick.Window 2.2
import "./qml"
Window {
    id: window
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Loader {
        id: loader
        anchors.fill: parent
        asynchronous: true
        focus: true
        sourceComponent:Main{

            anchors.fill: parent

        }

            MainForm {

        }
    }


}
