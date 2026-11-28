const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const s = input.trim();
    let stack = [-1], maxL=0;
    for(let i=0; i<s.length; i++) {
        if(s[i]==='(') stack.push(i);
        else {
            stack.pop();
            if(stack.length) maxL=Math.max(maxL, i-stack[stack.length-1]);
            else stack.push(i);
        }
    }
    console.log(maxL);
    rl.close();
});
