const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        let idx = 1;
        const rooms = [];
        for (let i = 0; i < n; i++) {
            const k = parseInt(tokens[idx++], 10);
            rooms.push(tokens.slice(idx, idx + k).map(Number));
            idx += k;
        }
        const vis = new Set([0]);
        const q = [0];
        while (q.length > 0) {
            const r = q.shift();
            for (const key of rooms[r]) {
                if (!vis.has(key)) {
                    vis.add(key);
                    q.push(key);
                }
            }
        }
        console.log(vis.size === n ? "true" : "false");
    }
}
main();