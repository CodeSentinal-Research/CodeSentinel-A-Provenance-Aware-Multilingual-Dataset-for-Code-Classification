const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const arr = lines[1].split(/\s+/).map(Number);
        let s = new Set(arr);
        let min = Math.min(...arr), max = Math.max(...arr);
        console.log(max - min + 1 === s.size ? "Yes" : "No");
        rl.close();
    }
});
