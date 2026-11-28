const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const s = input.trim();
    let stack = [];
    for(let i=s.length-1; i>=0; i--) {
        let c = s[i];
        if(c==='?') continue;
        else if(c===':') {
            let t = stack.pop(), f = stack.pop();
            let cond = s[i-1];
            stack.push(cond==='T' ? t : f);
            i--;
        } else {
            stack.push(c);
        }
    }
    console.log(stack[0]);
    rl.close();
});
