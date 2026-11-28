const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const [n, k] = lines[0].split(/\s+/).map(Number);
        const arr = lines[1].split(/\s+/).map(Number);
        arr.sort((a,b)=>a-b);
        let minDiff = Infinity;
        for(let i=0; i<=n-k; i++) {
            minDiff = Math.min(minDiff, arr[i+k-1]-arr[i]);
        }
        console.log(minDiff);
        rl.close();
    }
});
