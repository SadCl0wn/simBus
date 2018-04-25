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
                let begining = data.indexOf('<osm>');
                let ending = data.indexOf('</osm>');
                data = data.slice(begining, ending);

                let res = '';

                let isInsideTag = false;

                let i = 0;
                while(i < data.length){
                    if(data[i] === '<'){
                        isInsideTag = true;
                        i++;
                        let size = data.indexOf(' ', i);
                        res.push('{' + data.slice(i, i + size) + ',');
                        i += size;
                    }
                    else if(data[i] === '>'){
                        isInsideTag = false;                  
                    }

                    i++;
                }
                return res;
            }

            var xhr = new XMLHttpRequest();
            xhr.onreadystatechange = function() {
                if ( xhr.readyState == xhr.DONE )
                {
                    // var jsonObject = JSON.parse(xhr.responseText);
                    // console.log(jsonObject.toString());
                    // console.log(JSON.parse('{"data": "test"}').data);
                    // console.log(parseData(xhr.responseText));
                    console.log(parseData(a));
                }
            }
            var url = 'http://api.openstreetmap.org/api/0.6/map?bbox=-4.6388600,48.3521900,-4.6363600,48.3531700';
            xhr.open('GET', url, true);
            xhr.send();
        }
    }
}
