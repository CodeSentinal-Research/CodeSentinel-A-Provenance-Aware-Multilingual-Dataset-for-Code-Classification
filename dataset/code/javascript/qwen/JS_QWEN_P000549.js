const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 3) {
        const n = parseInt(lines[0]);
        const input = lines[1].split(/\s+/).map(Number);
        const output = lines[2].split(/\s+/).map(Number);
        let stack = [];
        let j=0;
        for(let x of input) {
            stack.push(x);
            while(stack.length && stack[stack.length-1]===output[j]) {
                stack.pop();
                j++;
            }
        }
        console.log(j===n ? "true" : "false");
        rl.close();
    }
});
