const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const heights = lines[1].split(/\s+/).map(Number);
        let res = new Array(n).fill(0);
        let stack = [];
        for(let i=n-1; i>=0; i--) {
            let count = 0;
            while(stack.length && heights[stack[stack.length-1]] < heights[i]) {
                stack.pop();
                count++;
            }
            if(stack.length) count++;
            res[i] = count;
            stack.push(i);
        }
        console.log(res.join(" "));
        rl.close();
    }
});
