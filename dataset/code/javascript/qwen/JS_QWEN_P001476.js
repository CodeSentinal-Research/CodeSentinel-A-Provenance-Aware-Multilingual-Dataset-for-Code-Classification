const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const heights = lines[1].split(/\s+/).map(Number);
        
        let leftMax = new Array(n), rightMax = new Array(n);
        leftMax[0] = heights[0];
        for (let i = 1; i < n; i++) leftMax[i] = Math.max(leftMax[i-1], heights[i]);
        rightMax[n-1] = heights[n-1];
        for (let i = n - 2; i >= 0; i--) rightMax[i] = Math.max(rightMax[i+1], heights[i]);
        
        let water = 0;
        for (let i = 0; i < n; i++) {
            water += Math.min(leftMax[i], rightMax[i]) - heights[i];
        }
        console.log(water);
        rl.close();
    }
});
