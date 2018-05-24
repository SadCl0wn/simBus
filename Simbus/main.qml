import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 1.4
import "parser.js" as Parser

Window {
    visible: true
    width: 150
    height: 50
    title: qsTr("Hello World")
    Button{
        x: 0
        y: 0
        width: 150
        height: 50
        text: "API osm test"
        onClicked: {
            Parser.parse();
        }
    }
}
