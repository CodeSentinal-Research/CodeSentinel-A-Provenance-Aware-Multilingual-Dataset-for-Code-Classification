const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const nums = tokens.slice(1, 1 + n).map(Number);
        const qCount = parseInt(tokens[1 + n], 10);
        let idx = 2 + n;
        const count = new Map();
        const q = [];
        for (const v of nums) {
            count.set(v, (count.get(v) || 0) + 1);
            q.push(v);
        }
        for (let i = 0; i < qCount; i++) {
            const cmd = tokens[idx];
            if (cmd === 'showFirstUnique') {
                while (q.length > 0 && count.get(q[0]) > 1) q.shift();
                console.log(q.length > 0 ? q[0] : -1);
                idx += 1;
            } else if (cmd === 'add') {
                const val = parseInt(tokens[idx+1], 10);
                count.set(val, (count.get(val) || 0) + 1);
                q.push(val);
                idx += 2;
            }
        }
    }
}
main();