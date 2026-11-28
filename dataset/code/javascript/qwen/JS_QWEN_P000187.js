const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const arr = lines[1].split(/\s+/).map(Number);
        let present = new Set(arr.filter(x=>x>0));
        let i=1;
        while(present.has(i)) i++;
        console.log(i);
        rl.close();
    }
});
