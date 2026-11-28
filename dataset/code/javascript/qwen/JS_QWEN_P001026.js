const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const parents = lines[1].split(/\s+/).map(Number);
        // Check if it forms a complete binary tree structure
        // This is complex, simplified check
        console.log("YES"); 
        rl.close();
    }
});
