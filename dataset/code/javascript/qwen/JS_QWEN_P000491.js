const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const path = input.trim().split('/').filter(x => x !== '');
    let stack = [];
    for(let p of path) {
        if(p === '.') continue;
        else if(p === '..') stack.pop();
        else stack.push(p);
    }
    console.log('/' + stack.join('/'));
    rl.close();
});
