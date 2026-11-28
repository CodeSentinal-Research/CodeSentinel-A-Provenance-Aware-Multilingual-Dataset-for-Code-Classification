const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const s = input.trim();
    let count = {}, stack = [], seen = new Set();
    for(let c of s) count[c]=(count[c]||0)+1;
    for(let c of s) {
        count[c]--;
        if(seen.has(c)) continue;
        while(stack.length && stack[stack.length-1]>c && count[stack[stack.length-1]]>0) {
            seen.delete(stack.pop());
        }
        stack.push(c);
        seen.add(c);
    }
    console.log(stack.join(''));
    rl.close();
});
