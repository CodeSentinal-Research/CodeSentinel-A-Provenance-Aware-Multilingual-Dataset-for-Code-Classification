const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const [n, k] = lines[0].split(/\s+/).map(Number);
        const nums = lines[1].split(/\s+/).map(Number);
        
        let count = 0;
        let isIncreasing = true;
        for (let i = 1; i < k; i++) {
            if (nums[i] <= nums[i-1]) isIncreasing = false;
        }
        if (isIncreasing) count++;
        
        for (let i = k; i < n; i++) {
            if (nums[i] <= nums[i-1]) isIncreasing = false;
            if (nums[i-k+1] <= nums[i-k]) {
                isIncreasing = true;
                for (let j = i - k + 1; j < i; j++) {
                    if (nums[j+1] <= nums[j]) {
                        isIncreasing = false;
                        break;
                    }
                }
            }
            if (isIncreasing) count++;
        }
        
        console.log(count);
        rl.close();
    }
});
