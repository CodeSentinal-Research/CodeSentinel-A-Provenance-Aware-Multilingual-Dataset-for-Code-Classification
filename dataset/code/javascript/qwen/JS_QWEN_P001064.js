const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 3) {
        const [n, m, q] = lines[0].split(/\s+/).map(Number);
        let edges = new Set();
        for(let i=1; i<=m; i++) {
            const [u, v] = lines[i].split(/\s+/).map(Number);
            edges.add(`${u},${v}`);
        }
        let res = [];
        for(let i=m+1; i<=m+q; i++) {
            const [u, v] = lines[i].split(/\s+/).map(Number);
            res.push(edges.has(`${u},${v}`) ? "YES" : "NO");
        }
        console.log(res.join("\n"));
        rl.close();
    }
});
