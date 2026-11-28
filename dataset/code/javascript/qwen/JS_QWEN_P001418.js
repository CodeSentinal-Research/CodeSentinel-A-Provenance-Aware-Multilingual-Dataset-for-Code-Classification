const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 2) {
        const n = parseInt(lines[0]);
        const allowed = lines[1];
        let count = 0;
        for (let i = 2; i < 2 + n; i++) {
            let word = lines[i];
            let valid = true;
            for (let c of word) {
                if (!allowed.includes(c)) { valid = false; break; }
            }
            if (valid) count++;
        }
        console.log(count);
        rl.close();
    }
});
