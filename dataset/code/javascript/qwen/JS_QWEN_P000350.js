const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const [s, kStr] = lines[0].split(/\s+/);
        const k = parseInt(kStr);
        let stack = [];
        for(let c of s) {
            stack.push(c);
            if(stack.length >= k) {
                let sub = stack.slice(-k).join('');
                if(new Set(sub).size === 1) stack.splice(-k);
            }
        }
        console.log(stack.join(''));
        rl.close();
    }
});
