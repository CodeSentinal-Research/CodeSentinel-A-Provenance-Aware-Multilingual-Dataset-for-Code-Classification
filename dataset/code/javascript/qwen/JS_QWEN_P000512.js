const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 3) {
        const n = parseInt(lines[0]);
        const pushed = lines[1].split(/\s+/).map(Number);
        const popped = lines[2].split(/\s+/).map(Number);
        let stack = [], j=0;
        for(let x of pushed) {
            stack.push(x);
            while(stack.length && stack[stack.length-1]===popped[j]) {
                stack.pop();
                j++;
            }
        }
        console.log(stack.length===0 ? "true" : "false");
        rl.close();
    }
});
