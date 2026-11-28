const fs = require('fs');

function addBoldTag(s, words) {
    const n = s.length;
    const bold = new Array(n).fill(false);
    for (const w of words) {
        let pos = s.indexOf(w);
        while (pos !== -1) {
            for (let i = pos; i < pos + w.length; i++) bold[i] = true;
            pos = s.indexOf(w, pos + 1);
        }
    }
    let res = '';
    for (let i = 0; i < n; ) {
        if (bold[i]) {
            res += '<b>';
            while (i < n && bold[i]) res += s[i++];
            res += '</b>';
        } else {
            res += s[i++];
        }
    }
    return res;
}

function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const s = tokens[0];
        const words = tokens.slice(1);
        console.log(addBoldTag(s, words));
    }
}

main();