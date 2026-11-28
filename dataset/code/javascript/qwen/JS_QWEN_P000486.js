const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const height = lines[1].split(/\s+/).map(Number);
        let left = new Array(n), right = new Array(n);
        left[0] = height[0];
        for(let i=1; i<n; i++) left[i] = Math.max(left[i-1], height[i]);
        right[n-1] = height[n-1];
        for(let i=n-2; i>=0; i--) right[i] = Math.max(right[i+1], height[i]);
        let water = 0;
        for(let i=0; i<n; i++) water += Math.min(left[i], right[i]) - height[i];
        console.log(water);
        rl.close();
    }
});
