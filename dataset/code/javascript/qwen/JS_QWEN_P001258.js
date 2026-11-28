const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const s = input.trim();
    let stack = [];
    let seen = new Set();
    let lastIdx = {};
    for(let i=0; i<s.length; i++) lastIdx[s[i]]=i;
    
    for(let i=0; i<s.length; i++) {
        if(seen.has(s[i])) continue;
        while(stack.length && stack[stack.length-1]>s[i] && lastIdx[stack[stack.length-1]]>i) {
            seen.delete(stack.pop());
        }
        stack.push(s[i]);
        seen.add(s[i]);
    }
    console.log(stack.join(''));
    rl.close();
});
