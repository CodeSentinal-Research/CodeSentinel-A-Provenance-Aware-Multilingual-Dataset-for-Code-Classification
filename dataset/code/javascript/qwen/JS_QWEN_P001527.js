const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const nums = lines[1].split(/\s+/).map(Number);
        
        let minLen = Infinity;
        let sum = 0;
        let left = 0;
        
        for (let right = 0; right < n; right++) {
            sum += nums[right];
            if (sum > 0) {
                minLen = Math.min(minLen, right - left + 1);
                // Reset window
                sum = 0;
                left = right + 1;
            }
        }
        
        console.log(minLen === Infinity ? -1 : minLen);
        rl.close();
    }
});
