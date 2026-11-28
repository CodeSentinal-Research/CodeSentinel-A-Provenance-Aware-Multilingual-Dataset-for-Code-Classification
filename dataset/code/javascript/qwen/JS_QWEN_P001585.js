const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const [n, k] = lines[0].split(/\s+/).map(Number);
        const nums = lines[1].split(/\s+/).map(Number);
        
        nums.sort((a, b) => a - b);
        
        let left = 0;
        let right = n - 1;
        let maxFreq = 0;
        
        while (left <= right) {
            let mid = Math.floor((left + right) / 2);
            let cost = 0;
            for (let i = mid; i < n; i++) {
                cost += nums[i] - nums[mid];
            }
            
            if (cost <= k) {
                maxFreq = n - mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        console.log(maxFreq);
        rl.close();
    }
});
