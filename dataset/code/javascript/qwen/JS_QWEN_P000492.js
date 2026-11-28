const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const num = lines[0];
        const k = parseInt(lines[1]);
        let stack = [];
        for(let c of num) {
            while(k>0 && stack.length && stack[stack.length-1]>c) {
                stack.pop();
                k--;
            }
            stack.push(c);
        }
        while(k>0) { stack.pop(); k--; }
        let res = stack.join('').replace(/^0+/, '');
        console.log(res || "0");
        rl.close();
    }
});
