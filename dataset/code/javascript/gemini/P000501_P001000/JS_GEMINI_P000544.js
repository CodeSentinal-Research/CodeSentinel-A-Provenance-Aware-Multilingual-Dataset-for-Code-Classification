const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 2 && tokens[0] !== '') {
        const d = parseInt(tokens[0], 10);
        const deadends = new Set(tokens.slice(1, 1 + d));
        const target = tokens[1 + d];
        if (deadends.has("0000")) { console.log(-1); return; }
        if (target === "0000") { console.log(0); return; }
        const q = [["0000", 0]];
        deadends.add("0000");
        let ans = -1;
        while (q.length > 0) {
            const [cur, dist] = q.shift();
            if (cur === target) { ans = dist; break; }
            for (let i = 0; i < 4; i++) {
                const digit = parseInt(cur[i], 10);
                for (const diff of [-1, 1]) {
                    const nxtDigit = (digit + diff + 10) % 10;
                    const nxt = cur.slice(0, i) + nxtDigit + cur.slice(i + 1);
                    if (!deadends.has(nxt)) {
                        deadends.add(nxt);
                        q.push([nxt, dist + 1]);
                    }
                }
            }
        }
        console.log(ans);
    }
}
main();