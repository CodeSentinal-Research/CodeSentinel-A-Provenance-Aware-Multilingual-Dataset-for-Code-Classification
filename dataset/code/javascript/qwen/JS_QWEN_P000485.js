const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const heights = lines[1].split(/\s+/).map(Number);
        let stack = [], maxArea = 0;
        for(let i=0; i<=n; i++) {
            let h = i===n ? 0 : heights[i];
            while(stack.length && heights[stack[stack.length-1]] > h) {
                let height = heights[stack.pop()];
                let width = stack.length ? i-stack[stack.length-1]-1 : i;
                maxArea = Math.max(maxArea, height*width);
            }
            stack.push(i);
        }
        console.log(maxArea);
        rl.close();
    }
});
