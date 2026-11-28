const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const nums = lines[1].split(/\s+/).map(Number);
        
        let maxLen = 0;
        let bitmask = 0;
        let left = 0;
        
        for (let right = 0; right < n; right++) {
            while ((bitmask & nums[right]) !== 0) {
                bitmask ^= nums[left];
                left++;
            }
            bitmask |= nums[right];
            maxLen = Math.max(maxLen, right - left + 1);
        }
        
        console.log(maxLen);
        rl.close();
    }
});
