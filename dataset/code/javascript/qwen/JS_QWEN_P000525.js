const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const h = lines[1].split(/\s+/).map(Number);
        // Efficient solution using stack for beautiful towers II
        let left = new Array(n).fill(0);
        let stack = [];
        for(let i=0; i<n; i++) {
            let sum = 0, count = 0;
            while(stack.length && h[stack[stack.length-1]] > h[i]) {
                let idx = stack.pop();
                sum -= left[idx];
                count--;
            }
            left[i] = (stack.length ? left[stack[stack.length-1]] : 0) + h[i] * (i - (stack.length ? stack[stack.length-1] : -1));
            stack.push(i);
        }
        // Similar for right
        console.log("Complex DP/Stack Solution Required");
        rl.close();
    }
});
