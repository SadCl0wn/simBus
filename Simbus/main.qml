import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 1.4

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
            function parseData(data){
                var res = {};
                data.getElementByTagName('way').foreach(function(i){
                    if(i.lastChild.tagName === 'way'){
                        if(i.getElementByTagName('tag')[0].attributes.k === 'highway'){
                            res[i.getElementByTagName('tag')[2].attributes.v] = [];
                            // for
                        }
                    }
                });

                return res;
            }

            var xhr = new XMLHttpRequest();
            xhr.onreadystatechange = function() {
                if ( xhr.readyState == xhr.DONE )
                {
                    console.log(parseData(xhr.responseXML).toString());
                    // console.log(xhr.responseXML.toString());
                }
            }
            var url = 'https://api.openstreetmap.org/api/0.6/map?bbox=-4.6388600,48.3521900,-4.6363600,48.3531700';
            xhr.open('GET', url, true);
            xhr.send();
        }
    }
}
