const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const nums = lines[1].split(/\s+/).map(Number);
        
        let sorted = [...nums].sort((a, b) => a - b);
        let chunks = 0;
        let sum1 = 0, sum2 = 0;
        
        for (let i = 0; i < n; i++) {
            sum1 += nums[i];
            sum2 += sorted[i];
            if (sum1 === sum2) chunks++;
        }
        
        console.log(chunks);
        rl.close();
    }
});
