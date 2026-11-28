const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 2) {
        const n = parseInt(lines[0]);
        let edges = 0;
        for(let i=1; i<=n; i++) {
            const neighbors = lines[i].split(/\s+/).map(Number);
            edges += neighbors.length;
        }
        console.log(edges/2);
        rl.close();
    }
});
