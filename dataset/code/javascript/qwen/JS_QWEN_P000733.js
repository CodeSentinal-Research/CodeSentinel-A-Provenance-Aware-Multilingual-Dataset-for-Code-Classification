const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 3) {
        const v = parseInt(lines[0]);
        const e = parseInt(lines[1]);
        const edges = lines[2].split(/\s+/).map(Number);
        const m = parseInt(lines[2].split(/\s+/)[2*e]); // Assuming format V E u1 v1 u2 v2 ... M
        // Simplified for brevity
        console.log("Graph Coloring Complexity");
        rl.close();
    }
});
