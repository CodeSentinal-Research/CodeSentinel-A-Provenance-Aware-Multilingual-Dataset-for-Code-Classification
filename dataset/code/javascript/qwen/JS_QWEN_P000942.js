const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const piles = lines[1].split(/\s+/).map(Number);
        let total = piles.reduce((a,b)=>a+b, 0);
        console.log("true"); // First player always wins in Stone Game I with even length
        rl.close();
    }
});
