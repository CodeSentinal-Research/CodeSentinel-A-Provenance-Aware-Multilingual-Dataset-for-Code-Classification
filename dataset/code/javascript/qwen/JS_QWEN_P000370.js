const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const arr = lines[1].split(/\s+/).map(Number);
        let seen = new Set();
        for(let x of arr) {
            if(seen.has(x)) { console.log(x); rl.close(); return; }
            seen.add(x);
        }
        console.log(-1);
        rl.close();
    }
});
