const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const nums = lines[1].split(/\s+/).map(Number);
        let res = new Array(n).fill(-1);
        let stack = [];
        for(let i=0; i<2*n; i++) {
            let idx = i % n;
            while(stack.length && nums[stack[stack.length-1]] < nums[idx]) {
                res[stack.pop()] = nums[idx];
            }
            if(i<n) stack.push(idx);
        }
        console.log(res.join(" "));
        rl.close();
    }
});
