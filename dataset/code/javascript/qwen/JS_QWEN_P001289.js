const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const nums = lines[1].split(/\s+/).map(Number);
        
        nums.sort((a,b)=>a-b);
        let maxSum=0;
        for(let i=0; i<n/2; i++) {
            maxSum = Math.max(maxSum, nums[i]+nums[n-1-i]);
        }
        console.log(maxSum);
        rl.close();
    }
});
