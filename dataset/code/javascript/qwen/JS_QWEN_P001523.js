const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const [n, limit] = lines[0].split(/\s+/).map(Number);
        const nums = lines[1].split(/\s+/).map(Number);
        
        let maxLen = 0;
        let dequeMin = [], dequeMax = [];
        let left = 0;
        
        for (let right = 0; right < n; right++) {
            while (dequeMin.length && nums[dequeMin[dequeMin.length - 1]] >= nums[right]) dequeMin.pop();
            dequeMin.push(right);
            
            while (dequeMax.length && nums[dequeMax[dequeMax.length - 1]] <= nums[right]) dequeMax.pop();
            dequeMax.push(right);
            
            while (nums[dequeMax[0]] - nums[dequeMin[0]] > limit) {
                left++;
                if (dequeMin[0] < left) dequeMin.shift();
                if (dequeMax[0] < left) dequeMax.shift();
            }
            
            maxLen = Math.max(maxLen, right - left + 1);
        }
        
        console.log(maxLen);
        rl.close();
    }
});
