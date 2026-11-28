const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 2) {
        const n = parseInt(lines[0]);
        let masks = [];
        for (let i = 1; i <= n; i++) {
            let mask = 0;
            for (let c of lines[i]) mask |= (1 << (c.charCodeAt(0) - 97));
            masks.push(mask);
        }
        
        let count = 0;
        for (let i = 0; i < n; i++) {
            for (let j = i + 1; j < n; j++) {
                if (masks[i] === masks[j]) count++;
            }
        }
        console.log(count);
        rl.close();
    }
});
