const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 3) {
        const n = parseInt(lines[0]);
        const a = lines[1].split(/\s+/).map(Number);
        const b = lines[2].split(/\s+/).map(Number);
        
        let ops = 0;
        let diffA = 0;
        let diffB = 0;
        for (let i = 0; i < n; i++) {
            diffA += a[i];
            diffB += b[i];
            if (diffA < diffB) {
                ops += (diffB - diffA);
                diffA = diffB;
            }
        }
        console.log(ops);
        rl.close();
    }
});
