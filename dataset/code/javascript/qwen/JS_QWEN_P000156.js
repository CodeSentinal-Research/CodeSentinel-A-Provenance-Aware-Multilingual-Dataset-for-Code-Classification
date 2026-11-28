const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const arr = lines[1].split(/\s+/).map(Number);
        let maxC=0, curr=0;
        arr.forEach(x => {
            if(x===0) curr++;
            else curr=0;
            maxC = Math.max(maxC, curr);
        });
        console.log(maxC);
        rl.close();
    }
});
