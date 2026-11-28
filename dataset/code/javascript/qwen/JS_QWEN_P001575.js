const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const [n, k] = lines[0].split(/\s+/).map(Number);
        const nums = lines[1].split(/\s+/).map(Number);
        
        let minVal = nums[0];
        for (let i = 1; i < k; i++) {
            minVal = Math.min(minVal, nums[i]);
        }
        
        console.log(minVal);
        rl.close();
    }
});
