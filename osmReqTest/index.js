function parseData(data) {
    let begining = data.indexOf('<osm');
    let ending = data.indexOf('</osm>');
    data = data.slice(begining, ending + 6);

    let res = '';

    let isInsideTag = false;

    let i = 0;
    while (i < data.length) {
        if (data[i] === '<') {
            isInsideTag = true;
            let size = data.indexOf(' ', i);
            res += '{"' + data.slice(i + 1, size) + '":[';
            i = size;
        } else if (data[i] === '>') {
            if (data[i - 1] === '/') {
                res += ']';
            } else {
                res += 'child:[';
            }
            isInsideTag = false;
        } else if (isInsideTag) {
            if (data[i] != ' ') {
                let size = data.indexOf('=', i);
                res += '"' + data.slice(i, size) + '"';
                i = size;
                size = data.indexOf('"', i + 2);
                res += data.slice(i, size + 1);
                res += ',';
                i = size;
            }
        }

        i++;
    }
    return res;
}

var a = `<?xml version="1.0" encoding="UTF-8"?>
<osm version="0.6" generator="CGImap 0.6.0 (9711 thorn-01.openstreetmap.org)" copyright="OpenStreetMap and contributors" attribution="http://www.openstreetmap.org/copyright" license="http://opendatacommons.org/licenses/odbl/1-0/">
    <bounds minlat="48.3521900" minlon="-4.6388600" maxlat="48.3531700" maxlon="-4.6363600"/>
    <node id="1186380318" visible="true" version="1" changeset="7458074" timestamp="2011-03-04T21:21:18Z" user="FVig" uid="187752" lat="48.3552519" lon="-4.6331707"/>
    <way id="135965285" visible="true" version="4" changeset="54211234" timestamp="2017-11-30T17:20:42Z" user="Olyon" uid="1443767">
        <nd ref="1186372969"/>
    </way>
</osm>`;

console.log(parseData(a));
