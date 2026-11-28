const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const nums = lines[1].split(/\s+/).map(Number);
        
        let count = {};
        for (let x of nums) count[x] = (count[x] || 0) + 1;
        
        let valid = true;
        for (let x in count) {
            if (count[x] % 2 !== 0) { valid = false; break; }
        }
        console.log(valid ? "YES" : "NO");
        rl.close();
    }
});
