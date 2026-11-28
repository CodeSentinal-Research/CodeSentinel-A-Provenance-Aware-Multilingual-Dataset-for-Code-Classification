const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === parseInt(lines[0].split(' ')[0])+1) {
        const [r, c] = lines[0].split(/\s+/).map(Number);
        let mat = [];
        for(let i=1; i<=r; i++) mat.push(lines[i].split(/\s+/).map(Number));
        let heights = new Array(c).fill(0);
        let maxArea = 0;
        for(let i=0; i<r; i++) {
            for(let j=0; j<c; j++) heights[j] = mat[i][j]===1 ? heights[j]+1 : 0;
            // Largest rectangle in histogram
            let stack = [], maxH=0;
            for(let j=0; j<=c; j++) {
                let h = j===c ? 0 : heights[j];
                while(stack.length && heights[stack[stack.length-1]] > h) {
                    let height = heights[stack.pop()];
                    let width = stack.length ? j-stack[stack.length-1]-1 : j;
                    maxH = Math.max(maxH, height*width);
                }
                stack.push(j);
            }
            maxArea = Math.max(maxArea, maxH);
        }
        console.log(maxArea);
        rl.close();
    }
});
