const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const arr = lines[1].split(/\s+/).map(Number);
        const unique = [...new Set(arr)].sort((a,b) => a-b);
        console.log(unique.length > 1 ? unique[1] : -1);
        rl.close();
    }
});
