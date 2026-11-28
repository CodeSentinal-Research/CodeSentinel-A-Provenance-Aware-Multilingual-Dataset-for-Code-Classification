const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const arr = lines[1].split(/\s+/).map(Number);
        let total = arr.reduce((a,b)=>a+b, 0);
        let maxKadane = arr[0], curr = arr[0];
        for(let i=1; i<n; i++) {
            curr = Math.max(arr[i], curr+arr[i]);
            maxKadane = Math.max(maxKadane, curr);
        }
        let minKadane = arr[0]; curr = arr[0];
        for(let i=1; i<n; i++) {
            curr = Math.min(arr[i], curr+arr[i]);
            minKadane = Math.min(minKadane, curr);
        }
        console.log(total === minKadane ? maxKadane : Math.max(maxKadane, total-minKadane));
        rl.close();
    }
});
