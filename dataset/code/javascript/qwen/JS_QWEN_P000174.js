const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const arr = lines[1].split(/\s+/).map(Number);
        arr.sort((a,b)=>a-b);
        let minD = Infinity;
        for(let i=1; i<n; i++) minD = Math.min(minD, arr[i]-arr[i-1]);
        console.log(minD);
        rl.close();
    }
});
