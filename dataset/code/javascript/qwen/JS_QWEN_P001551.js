const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const [n, k] = lines[0].split(/\s+/).map(Number);
        const nums = lines[1].split(/\s+/).map(Number);
        
        let left = 0;
        let sum = 0;
        let maxLen = 0;
        
        for (let right = 0; right < n; right++) {
            sum += nums[right];
            while (sum > k) {
                sum -= nums[left];
                left++;
            }
            maxLen = Math.max(maxLen, right - left + 1);
        }
        
        console.log(maxLen);
        rl.close();
    }
});
