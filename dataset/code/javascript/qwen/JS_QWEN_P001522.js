const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const [n, x] = lines[0].split(/\s+/).map(Number);
        const nums = lines[1].split(/\s+/).map(Number);
        
        let totalSum = nums.reduce((a, b) => a + b, 0);
        let targetSubarraySum = totalSum - x;
        
        if (targetSubarraySum === 0) { console.log(n); rl.close(); return; }
        if (targetSubarraySum < 0) { console.log(-1); rl.close(); return; }
        
        let left = 0;
        let currentSum = 0;
        let maxSubarrayLen = -1;
        
        for (let right = 0; right < n; right++) {
            currentSum += nums[right];
            while (currentSum > targetSubarraySum && left <= right) {
                currentSum -= nums[left];
                left++;
            }
            if (currentSum === targetSubarraySum) {
                maxSubarrayLen = Math.max(maxSubarrayLen, right - left + 1);
            }
        }
        
        console.log(maxSubarrayLen === -1 ? -1 : n - maxSubarrayLen);
        rl.close();
    }
});
