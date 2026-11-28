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
        
        let keys = Object.keys(count).map(Number).sort((a,b)=>a-b);
        let maxLen = 0;
        for (let i = 0; i < keys.length; i++) {
            if (keys[i+1] === keys[i] + 1) {
                // Check logic for harmonious subsequence
            }
        }
        // Simplified approach for distinct values
        let sorted = [...new Set(nums)].sort((a,b)=>a-b);
        let res = 0;
        for (let i = 0; i < sorted.length - 1; i++) {
            if (sorted[i+1] - sorted[i] === 1) {
                res = Math.max(res, count[sorted[i]] + count[sorted[i+1]]);
            }
        }
        console.log(res);
        rl.close();
    }
});
