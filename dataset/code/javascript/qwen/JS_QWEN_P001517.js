const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const nums = lines[1].split(/\s+/).map(Number);
        
        nums.sort((a, b) => a - b);
        
        let minMaxSum = 0;
        let left = 0;
        let right = n - 1;
        
        while (left < right) {
            minMaxSum = Math.max(minMaxSum, nums[left] + nums[right]);
            left++;
            right--;
        }
        
        console.log(minMaxSum);
        rl.close();
    }
});
