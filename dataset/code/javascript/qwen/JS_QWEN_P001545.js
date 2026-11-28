const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const [n, k] = lines[0].split(/\s+/).map(Number);
        const nums = lines[1].split(/\s+/).map(Number);
        
        let minDiff = Infinity;
        
        // Use a sorted structure or just sort the window (inefficient but simple for N=10^5 if K is small, but K can be large)
        // Better: Use two deques for min and max in sliding window
        
        let dequeMin = [], dequeMax = [];
        
        for (let i = 0; i < n; i++) {
            while (dequeMin.length && nums[dequeMin[dequeMin.length - 1]] >= nums[i]) dequeMin.pop();
            dequeMin.push(i);
            
            while (dequeMax.length && nums[dequeMax[dequeMax.length - 1]] <= nums[i]) dequeMax.pop();
            dequeMax.push(i);
            
            if (i >= k - 1) {
                let minVal = nums[dequeMin[0]];
                let maxVal = nums[dequeMax[0]];
                minDiff = Math.min(minDiff, maxVal - minVal);
                
                if (dequeMin[0] <= i - k + 1) dequeMin.shift();
                if (dequeMax[0] <= i - k + 1) dequeMax.shift();
            }
        }
        
        console.log(minDiff);
        rl.close();
    }
});
