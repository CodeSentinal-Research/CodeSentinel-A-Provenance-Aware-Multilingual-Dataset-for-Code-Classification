const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const q = parseInt(tokens[0], 10);
        let idx = 1;
        const d = new Map();
        for (let j = 0; j < q; j++) {
            const cmd = tokens[idx];
            if (cmd === 'put') {
                d.set(tokens[idx+1], tokens[idx+2]);
                idx += 3;
            } else if (cmd === 'get') {
                const k = tokens[idx+1];
                console.log(d.has(k) ? d.get(k) : -1);
                idx += 2;
            } else if (cmd === 'remove') {
                d.delete(tokens[idx+1]);
                idx += 2;
            } else if (cmd === 'firstKey') {
                const keys = Array.from(d.keys()).sort();
                console.log(keys.length > 0 ? keys[0] : '');
                idx += 1;
            } else if (cmd === 'lastKey') {
                const keys = Array.from(d.keys()).sort();
                console.log(keys.length > 0 ? keys[keys.length - 1] : '');
                idx += 1;
            } else if (cmd === 'nextKey') {
                const k = tokens[idx+1];
                const keys = Array.from(d.keys()).sort();
                const nxt = keys.find(x => x > k);
                console.log(nxt !== undefined ? nxt : '');
                idx += 2;
            } else if (cmd === 'previousKey') {
                const k = tokens[idx+1];
                const keys = Array.from(d.keys()).sort();
                const prev = keys.filter(x => x < k).pop();
                console.log(prev !== undefined ? prev : '');
                idx += 2;
            }
        }
    }
}
main();