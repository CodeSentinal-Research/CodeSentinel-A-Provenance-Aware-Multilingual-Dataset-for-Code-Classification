const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const arr = lines[1].split(/\s+/).map(Number);
        let len=1, maxL=1;
        for(let i=1; i<n; i++) {
            if(arr[i]<arr[i-1]) len++;
            else len=1;
            maxL = Math.max(maxL, len);
        }
        console.log(maxL);
        rl.close();
    }
});
