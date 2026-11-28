const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 3) {
        const n = parseInt(lines[0]);
        const q = lines[1].split(/\s+/).map(Number);
        const k = parseInt(lines[2]);
        for(let i=0; i<k; i++) q.push(q.shift());
        console.log(q.join(" "));
        rl.close();
    }
});
