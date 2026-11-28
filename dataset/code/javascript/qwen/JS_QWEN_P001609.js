const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const nums = lines[1].split(/\s+/).map(Number);
        
        let total = nums.reduce((a,b)=>a+b, 0);
        let leftSum = 0;
        let count = 0;
        for (let i = 0; i < n; i++) {
            let rightSum = total - leftSum - nums[i];
            if (leftSum === rightSum) count++;
            leftSum += nums[i];
        }
        console.log(count);
        rl.close();
    }
});
