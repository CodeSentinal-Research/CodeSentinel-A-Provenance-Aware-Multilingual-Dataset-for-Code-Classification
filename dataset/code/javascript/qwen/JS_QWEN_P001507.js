const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const nums = lines[1].split(/\s+/).map(Number);
        
        let maxLen = 0;
        let currLen = 1;
        
        for (let i = 1; i < n; i++) {
            if ((nums[i] > nums[i-1] && nums[i-1] < nums[i-2]) || 
                (nums[i] < nums[i-1] && nums[i-1] > nums[i-2])) {
                currLen++;
            } else {
                currLen = 2; // Reset to 2 because any pair is turbulent
                if (i === 1) currLen = nums[i] !== nums[i-1] ? 2 : 1;
            }
            maxLen = Math.max(maxLen, currLen);
        }
        
        // Handle edge cases for small arrays
        if (n === 1) maxLen = 1;
        else if (n === 2) maxLen = nums[0] !== nums[1] ? 2 : 1;
        
        console.log(maxLen);
        rl.close();
    }
});
