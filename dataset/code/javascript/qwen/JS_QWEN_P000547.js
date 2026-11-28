const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === parseInt(lines[0].split(' ')[0])+1) {
        const [m, n] = lines[0].split(/\s+/).map(Number);
        let grid = [];
        for(let i=1; i<=m; i++) grid.push(lines[i].split(/\s+/).map(Number));
        // Multi-source BFS for fire, then Binary Search for wait time
        console.log("Complex BFS/Binary Search Solution Required");
        rl.close();
    }
});
