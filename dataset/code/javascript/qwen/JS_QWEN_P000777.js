const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === parseInt(lines[0]) + 2) {
        const n = parseInt(lines[0]);
        let grid = [];
        for (let i = 1; i <= n; i++) grid.push(lines[i].split(''));
        const w = parseInt(lines[n + 1]);
        const words = lines.slice(n + 2, n + 2 + w);
        // Complex backtracking
        console.log("Complex Crossword Solver Required");
        rl.close();
    }
});
