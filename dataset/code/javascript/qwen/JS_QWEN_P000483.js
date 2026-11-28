const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const s = input.trim();
    let stack = [];
    let i=0;
    while(i<s.length) {
        if(s[i]===']') {
            let str='', num='';
            while(stack.length && stack[stack.length-1]!=='[') str=stack.pop()+str;
            stack.pop();
            while(stack.length && /[0-9]/.test(stack[stack.length-1])) num=stack.pop()+num;
            stack.push(str.repeat(parseInt(num)));
        } else {
            stack.push(s[i]);
        }
        i++;
    }
    console.log(stack.join(''));
    rl.close();
});
