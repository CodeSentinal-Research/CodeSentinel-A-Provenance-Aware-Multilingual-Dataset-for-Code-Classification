const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const h = lines[1].split(/\s+/).map(Number);
        let left = new Array(n).fill(0);
        let right = new Array(n).fill(0);
        left[0] = h[0];
        for(let i=1; i<n; i++) left[i] = Math.min(left[i-1], h[i]);
        right[n-1] = h[n-1];
        for(let i=n-2; i>=0; i--) right[i] = Math.min(right[i+1], h[i]);
        let maxSum = 0;
        for(let i=0; i<n; i++) maxSum += Math.max(left[i], right[i]);
        console.log(maxSum);
        rl.close();
    }
});
