const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const [n, k] = lines[0].split(/\s+/).map(Number);
        const nums = lines[1].split(/\s+/).map(Number);
        
        let maxLen = 0;
        let oddCount = 0;
        let left = 0;
        
        for (let right = 0; right < n; right++) {
            if (nums[right] % 2 !== 0) oddCount++;
            
            while (oddCount > k) {
                if (nums[left] % 2 !== 0) oddCount--;
                left++;
            }
            
            maxLen = Math.max(maxLen, right - left + 1);
        }
        
        console.log(maxLen);
        rl.close();
    }
});
