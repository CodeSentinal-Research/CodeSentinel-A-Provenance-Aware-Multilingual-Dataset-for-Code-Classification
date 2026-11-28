const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const s = input.trim();
    let stack = [0];
    for(let c of s) {
        if(c==='(') stack.push(0);
        else if(c===')') {
            let v = stack.pop();
            stack[stack.length-1] += 2*v || 1;
        }
    }
    console.log(stack[0]);
    rl.close();
});
