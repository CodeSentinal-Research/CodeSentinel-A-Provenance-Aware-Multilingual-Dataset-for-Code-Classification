const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const heights = lines[1].split(/\s+/).map(Number);
        
        let l = 0, r = n - 1, maxArea = 0;
        while (l < r) {
            let h = Math.min(heights[l], heights[r]);
            maxArea = Math.max(maxArea, h * (r - l));
            if (heights[l] < heights[r]) l++;
            else r--;
        }
        console.log(maxArea);
        rl.close();
    }
});
