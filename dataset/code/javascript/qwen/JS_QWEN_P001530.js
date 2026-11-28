const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const nums = lines[1].split(/\s+/).map(Number);
        
        let maxSum = 0;
        let currentSum = 0;
        let set = new Set();
        let left = 0;
        
        for (let right = 0; right < n; right++) {
            while (set.has(nums[right])) {
                set.delete(nums[left]);
                currentSum -= nums[left];
                left++;
            }
            set.add(nums[right]);
            currentSum += nums[right];
            maxSum = Math.max(maxSum, currentSum);
        }
        
        console.log(maxSum);
        rl.close();
    }
});
