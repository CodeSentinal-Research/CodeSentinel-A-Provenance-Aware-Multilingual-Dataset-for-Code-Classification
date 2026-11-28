const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const nums = lines[1].split(/\s+/).map(Number);
        
        let total = (n * (n - 1)) / 2;
        let good = 0;
        let map = {};
        for (let i = 0; i < n; i++) {
            let val = nums[i] - i;
            if (map[val]) good += map[val];
            map[val] = (map[val] || 0) + 1;
        }
        console.log(total - good);
        rl.close();
    }
});
