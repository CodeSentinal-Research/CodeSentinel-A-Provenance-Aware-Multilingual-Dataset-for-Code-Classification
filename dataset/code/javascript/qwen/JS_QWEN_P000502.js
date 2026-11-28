const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === parseInt(lines[0])+1) {
        const n = parseInt(lines[0]);
        const tokens = lines[1].split(/\s+/);
        let stack = [];
        for(let t of tokens) {
            if(['+','-','*','/'].includes(t)) {
                let b = stack.pop(), a = stack.pop();
                if(t==='+') stack.push(a+b);
                else if(t==='-') stack.push(a-b);
                else if(t==='*') stack.push(a*b);
                else stack.push(Math.trunc(a/b));
            } else {
                stack.push(parseInt(t));
            }
        }
        console.log(stack[0]);
        rl.close();
    }
});
