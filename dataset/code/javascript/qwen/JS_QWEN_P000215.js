const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const [n, k] = lines[0].split(/\s+/).map(Number);
        const arr = lines[1].split(/\s+/).map(Number);
        let sum = arr.slice(0,k).reduce((a,b)=>a+b,0);
        let maxS = sum;
        for(let i=k; i<n; i++) {
            sum += arr[i] - arr[i-k];
            maxS = Math.max(maxS, sum);
        }
        console.log((maxS/k).toFixed(5));
        rl.close();
    }
});
