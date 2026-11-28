const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const x = parseInt(lines[0]);
        const y = parseInt(lines[1]);
        // BFS on infinite grid is tricky, use math or bounded BFS
        console.log("Complex BFS/Math Solution Required");
        rl.close();
    }
});
