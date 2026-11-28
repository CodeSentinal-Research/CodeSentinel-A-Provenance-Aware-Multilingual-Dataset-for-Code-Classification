const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 3) {
        const n = parseInt(lines[0]);
        const arr = lines[1].split(/\s+/).map(Number);
        const i = parseInt(lines[2]);
        let l = 2*i+1, r = 2*i+2;
        let left = l < n ? arr[l] : -1;
        let right = r < n ? arr[r] : -1;
        console.log(`${left} ${right}`);
        rl.close();
    }
});
