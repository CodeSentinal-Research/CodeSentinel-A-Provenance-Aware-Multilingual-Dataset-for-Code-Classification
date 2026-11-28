const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const s = input.trim();
    let stack = [];
    for(let c of s) {
        if(stack.length && ((c >= 'a' && c <= 'z' && stack[stack.length-1] === c.toUpperCase()) ||
                            (c >= 'A' && c <= 'Z' && stack[stack.length-1] === c.toLowerCase()))) {
            stack.pop();
        } else {
            stack.push(c);
        }
    }
    console.log(stack.join(''));
    rl.close();
});
