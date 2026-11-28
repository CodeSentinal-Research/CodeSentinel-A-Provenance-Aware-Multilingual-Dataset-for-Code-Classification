const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const prices = lines[1].split(/\s+/).map(Number);
        let res = [...prices];
        let stack = [];
        for(let i=0; i<n; i++) {
            while(stack.length && prices[stack[stack.length-1]] >= prices[i]) {
                res[stack.pop()] -= prices[i];
            }
            stack.push(i);
        }
        console.log(res.join(" "));
        rl.close();
    }
});
