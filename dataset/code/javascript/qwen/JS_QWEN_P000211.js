const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const arr = lines[1].split(/\s+/).map(Number);
        arr.sort((a,b)=>a-b);
        console.log(Math.max(arr[0]*arr[1]*arr[n-1], arr[n-1]*arr[n-2]*arr[n-3]));
        rl.close();
    }
});
