function parseXML(data) {
    let res = {
        elem: 'root',
        parent: null,
        children: [],
        attributes: {}
    };

    let dir = res;

    for (let i = 0; i < data.length; i++) {
        if (data[i] === '\n' || data[i] === ' ') {
        } else if (data[i] === '<') {
            //comment
            if (data[i + 1] === '?') {
                i = data.indexOf('?>') + 2;
            } //fin balise avec enfants
            else if (data[i + 1] === '/') {
                dir = dir.parent;
            } else {
                let nameEnd = data.indexOf(' ', i);
                dir.children.push({
                    elem: data.slice(i + 1, nameEnd),
                    parent: dir,
                    children: [],
                    attributes: {}
                });

                let attrString = data.slice(nameEnd, data.indexOf('>', i));
                for (let j = 0; j < attrString.length; j++) {
                    if (attrString[j] !== ' ') {
                        let keyEnd = attrString.indexOf('="', j);
                        if (keyEnd === -1) break;
                        let valueEnd = attrString.indexOf('"', keyEnd + 2);
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