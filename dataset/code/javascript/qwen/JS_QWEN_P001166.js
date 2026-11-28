const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const nums = lines[1].split(/\s+/).map(Number);
        let maxKadane = nums[0], minKadane = nums[0], total = nums[0];
        for(let i=1; i<n; i++) {
            maxKadane = Math.max(nums[i], maxKadane+nums[i]);
            minKadane = Math.min(nums[i], minKadane+nums[i]);
            total += nums[i];
        }
        console.log(total === minKadane ? maxKadane : Math.max(maxKadane, total-minKadane));
        rl.close();
    }
});
