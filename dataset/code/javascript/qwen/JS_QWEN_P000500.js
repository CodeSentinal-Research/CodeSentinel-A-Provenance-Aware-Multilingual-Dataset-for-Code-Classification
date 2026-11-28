const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const s = input.trim();
    let stack = [];
    for(let c of s) {
        if(c === ')') {
            let temp = [];
            while(stack.length && stack[stack.length-1] !== '(') temp.push(stack.pop());
            stack.pop(); // remove (
            stack.push(...temp.reverse());
        } else {
            stack.push(c);
        }
    }
    console.log(stack.join(''));
    rl.close();
});
