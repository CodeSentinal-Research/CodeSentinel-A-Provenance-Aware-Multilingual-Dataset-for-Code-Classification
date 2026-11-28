const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const arr = lines[1].split(/\s+/).map(Number);
        let left = new Array(n).fill(1);
        let right = new Array(n).fill(1);
        for(let i=1; i<n; i++) left[i] = left[i-1] * arr[i-1];
        for(let i=n-2; i>=0; i--) right[i] = right[i+1] * arr[i+1];
        let res = arr.map((_, i) => left[i] * right[i]);
        console.log(res.join(" "));
        rl.close();
    }
});
