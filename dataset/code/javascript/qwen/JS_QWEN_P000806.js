const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const nums = lines[1].split(/\s+/).map(Number);
        
        let map = {0: -1};
        let balance = 0;
        let maxLen = 0;
        for (let i = 0; i < n; i++) {
            balance += (nums[i] > 0 ? 1 : -1);
            if (map[balance] !== undefined) maxLen = Math.max(maxLen, i - map[balance]);
            else map[balance] = i;
        }
        console.log(maxLen);
        rl.close();
    }
});
