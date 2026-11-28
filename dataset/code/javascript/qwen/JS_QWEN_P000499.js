const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === parseInt(lines[0])+1) {
        const n = parseInt(lines[0]);
        let ops = lines.slice(1);
        let depth = 0;
        for(let op of ops) {
            if(op === "../") depth = Math.max(0, depth-1);
            else if(op !== "./") depth++;
        }
        console.log(depth);
        rl.close();
    }
});
