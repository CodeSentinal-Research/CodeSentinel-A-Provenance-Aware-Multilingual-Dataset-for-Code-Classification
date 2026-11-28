const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const arr = lines[1].split(/\s+/).map(Number);
        let minVal = arr[0], maxDiff = 0;
        for(let i=1; i<n; i++) {
            if(arr[i]-minVal > maxDiff) maxDiff = arr[i]-minVal;
            if(arr[i] < minVal) minVal = arr[i];
        }
        console.log(maxDiff);
        rl.close();
    }
});
