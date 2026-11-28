const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const nums = lines[1].split(/\s+/).map(Number);
        let max = 0;
        let mask = 0;
        for (let i = 31; i >= 0; i--) {
            mask |= (1 << i);
            let set = new Set();
            for (let x of nums) set.add(x & mask);
            let candidate = max | (1 << i);
            let found = false;
            for (let prefix of set) {
                if (set.has(candidate ^ prefix)) { found = true; break; }
            }
            if (found) max = candidate;
        }
        console.log(max);
        rl.close();
    }
});
