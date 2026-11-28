const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const q = parseInt(tokens[0], 10);
        let idx = 1;
        const cnt = new Map();
        for (let i = 0; i < q; i++) {
            const cmd = tokens[idx];
            if (cmd === 'add') {
                const x = parseInt(tokens[idx+1], 10);
                cnt.set(x, (cnt.get(x) || 0) + 1);
                idx += 2;
            } else if (cmd === 'search') {
                const x = parseInt(tokens[idx+1], 10);
                console.log((cnt.get(x) || 0) > 0 ? "true" : "false");
                idx += 2;
            } else if (cmd === 'erase') {
                const x = parseInt(tokens[idx+1], 10);
                if ((cnt.get(x) || 0) > 0) {
                    cnt.set(x, cnt.get(x) - 1);
                    console.log("true");
                } else {
                    console.log("false");
                }
                idx += 2;
            }
        }
    }
}
main();