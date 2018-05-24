function parseXML(data) {
    var res = {
        elem: 'root',
        parent: null,
        children: [],
        attributes: {}
    };

    var dir = res;

    for (var i = 0; i < data.length; i++) {
        if (data[i] === '\n' || data[i] === ' ') {
        } else if (data[i] === '<') {
            //comment
            if (data[i + 1] === '?') {
                i = data.indexOf('?>') + 2;
            } //fin balise avec enfants
            else if (data[i + 1] === '/') {
                dir = dir.parent;
            } else {
                var nameEnd = data.indexOf(' ', i);
                dir.children.push({
                    elem: data.slice(i + 1, nameEnd),
                    parent: dir,
                    children: [],
                    attributes: {}
                });

                var attrString = data.slice(nameEnd, data.indexOf('>', i));
                for (var j = 0; j < attrString.length; j++) {
                    if (attrString[j] !== ' ') {
                        var keyEnd = attrString.indexOf('="', j);
                        if (keyEnd === -1) break;
                        var valueEnd = attrString.indexOf('"', keyEnd + 2);
                        if (valueEnd === -1) valueEnd = attrString.length - 1;
                        dir.children[dir.children.length - 1].attributes[
                            attrString.slice(j, keyEnd)
                        ] = attrString.slice(keyEnd + 2, valueEnd);
                        j = valueEnd;
                    }
                }
                if (data[data.indexOf('>', i) - 1] !== '/') {
                    dir = dir.children[dir.children.length - 1];
                }
            }
        }
    }
    return res;
}

function instantiateAll(data) {
    data = data.children[0];
    var points = {};
    var obj = [];

    for (var i = 0; i < data.children.length; i++) {
        if (data.children[i].elem === 'node') {
            points['r' + data.children[i].attributes.id] = {
                x: data.children[i].attributes.lat,
                y: data.children[i].attributes.lon
            };
        } else if (data.children[i].elem === 'way') {
            for (var j = 0; j < data.children[i].children.length; j++) {
                if (
                    data.children[i].children[j].elem === 'tag' &&
                    data.children[i].children[j].attributes.k === 'highway'
                ) {
                    obj.push(data.children[i]);
                }
            }
        }
        for (var i = 0; i < data.children.length; i++) {}
    }
}

function parse() {
    var xhr = new XMLHttpRequest();
    xhr.onreadystatechange = function() {
        if (xhr.readyState == xhr.DONE) {
            instantiateAll(parseXML(xhr.responseText));
        }
    };
    var url =
        'https://api.openstreetmap.org/api/0.6/map?bbox=-4.5520,48.3733,-4.5321,48.3811&layers=T';
    xhr.open('GET', url, true);
    xhr.send();
}
