const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const arr = lines[1].split(/\s+/).map(Number);
        let minSum = arr[0], currSum = arr[0];
        for(let i=1; i<n; i++) {
            currSum = Math.min(arr[i], currSum+arr[i]);
            minSum = Math.min(minSum, currSum);
        }
        console.log(minSum);
        rl.close();
    }
});
