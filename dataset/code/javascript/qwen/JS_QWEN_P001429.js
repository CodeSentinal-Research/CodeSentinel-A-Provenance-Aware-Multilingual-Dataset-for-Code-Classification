const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const nums = lines[1].split(/\s+/).map(Number);
        
        let map = {};
        let count = 0;
        for (let i = 0; i < n; i++) {
            for (let j = i + 1; j < n; j++) {
                let prod = nums[i] * nums[j];
                if (map[prod]) count += map[prod];
                map[prod] = (map[prod] || 0) + 1;
            }
        }
        console.log(count * 8);
        rl.close();
    }
});
