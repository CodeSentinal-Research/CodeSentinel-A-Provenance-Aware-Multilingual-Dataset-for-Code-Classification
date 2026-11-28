const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const [n, k] = lines[0].split(/\s+/).map(Number);
        const nums = lines[1].split(/\s+/).map(Number);
        
        let count = 0;
        let allPositive = true;
        
        for (let i = 0; i < k; i++) {
            if (nums[i] <= 0) allPositive = false;
        }
        if (allPositive) count++;
        
        for (let i = k; i < n; i++) {
            if (nums[i] <= 0) allPositive = false;
            if (nums[i - k] <= 0) {
                // Need to recheck window
                allPositive = true;
                for (let j = i - k + 1; j <= i; j++) {
                    if (nums[j] <= 0) {
                        allPositive = false;
                        break;
                    }
                }
            }
            if (allPositive) count++;
        }
        
        console.log(count);
        rl.close();
    }
});
