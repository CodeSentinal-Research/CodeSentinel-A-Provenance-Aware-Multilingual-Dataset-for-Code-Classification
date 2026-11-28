const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const s = input.trim();
    let stack = [];
    for(let c of s) {
        if(c >= 'a' && c <= 'z') stack.push(c);
        else stack.pop();
    }
    console.log(stack.join(''));
    rl.close();
});
