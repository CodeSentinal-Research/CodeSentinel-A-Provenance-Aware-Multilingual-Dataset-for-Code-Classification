const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const nums = lines[1].split(/\s+/).map(Number);
        
        let maxLen = 0;
        let zeros = 0;
        let left = 0;
        
        for (let right = 0; right < n; right++) {
            if (nums[right] === 0) zeros++;
            
            while (zeros > 1) {
                if (nums[left] === 0) zeros--;
                left++;
            }
            
            maxLen = Math.max(maxLen, right - left + 1);
        }
        
        // If all are 1s, we must delete one, so length is n-1
        if (maxLen === n) maxLen--;
        
        console.log(maxLen);
        rl.close();
    }
});
