const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const q = parseInt(tokens[0], 10);
        let idx = 1;
        const s1 = [], s2 = [];
        for (let i = 0; i < q; i++) {
            const cmd = tokens[idx];
            if (cmd === 'push') {
                s1.push(parseInt(tokens[idx+1], 10));
                idx += 2;
            } else if (cmd === 'pop') {
                if (s2.length === 0) while (s1.length > 0) s2.push(s1.pop());
                if (s2.length > 0) console.log(s2.pop());
                idx += 1;
            } else if (cmd === 'peek') {
                if (s2.length === 0) while (s1.length > 0) s2.push(s1.pop());
                if (s2.length > 0) console.log(s2[s2.length - 1]);
                idx += 1;
            } else if (cmd === 'empty') {
                console.log(s1.length === 0 && s2.length === 0 ? "true" : "false");
                idx += 1;
            }
        }
    }
}
main();