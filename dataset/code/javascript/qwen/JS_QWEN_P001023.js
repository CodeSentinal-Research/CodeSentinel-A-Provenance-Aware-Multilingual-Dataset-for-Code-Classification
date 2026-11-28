const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 3) {
        const n = parseInt(lines[0]);
        const arr = lines[1].split(/\s+/).map(Number);
        const i = parseInt(lines[2]);
        if(i === 0) console.log(-1);
        else console.log(arr[Math.floor((i-1)/2)]);
        rl.close();
    }
});
