const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const arr = lines[1].split(/\s+/).map(Number);
        let stack = [];
        for(let x of arr) {
            while(stack.length && stack[stack.length-1] < x) stack.pop();
            stack.push(x);
        }
        console.log(stack.join(" "));
        rl.close();
    }
});
