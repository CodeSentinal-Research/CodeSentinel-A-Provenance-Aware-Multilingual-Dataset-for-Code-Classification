const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const q = lines[1].split(/\s+/).map(Number);
        let stack = [];
        while(q.length) stack.push(q.shift());
        while(stack.length) q.push(stack.pop());
        console.log(q.join(" "));
        rl.close();
    }
});
