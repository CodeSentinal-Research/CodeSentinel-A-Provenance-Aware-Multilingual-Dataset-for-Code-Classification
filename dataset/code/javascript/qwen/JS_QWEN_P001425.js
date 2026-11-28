const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 2) {
        const n = parseInt(lines[0]);
        let sources = new Set(), dests = new Set();
        for (let i = 1; i <= n; i++) {
            const [s, d] = lines[i].split(/\s+/);
            sources.add(s);
            dests.add(d);
        }
        for (let d of dests) {
            if (!sources.has(d)) { console.log(d); rl.close(); return; }
        }
        rl.close();
    }
});
