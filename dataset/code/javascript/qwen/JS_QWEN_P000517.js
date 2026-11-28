const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const arr = lines[1].split(/\s+/).map(Number);
        let minRight = new Array(n).fill(arr[n-1]);
        for(let i=n-2; i>=0; i--) minRight[i] = Math.min(minRight[i+1], arr[i]);
        let maxLeft = arr[0], maxWidth = 0;
        for(let i=0; i<n; i++) {
            maxLeft = Math.max(maxLeft, arr[i]);
            if(maxLeft <= minRight[i]) maxWidth = Math.max(maxWidth, n-1-i);
        }
        console.log(maxWidth);
        rl.close();
    }
});
