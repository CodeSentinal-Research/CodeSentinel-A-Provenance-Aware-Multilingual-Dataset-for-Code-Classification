const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const nums = lines[1].split(/\s+/).map(Number);
        
        let maxLen = 0;
        let diff = 0; // evens - odds
        let map = {0: -1};
        
        for (let i = 0; i < n; i++) {
            if (nums[i] % 2 === 0) diff++;
            else diff--;
            
            if (map[diff] !== undefined) {
                maxLen = Math.max(maxLen, i - map[diff]);
            } else {
                map[diff] = i;
            }
        }
        
        console.log(maxLen);
        rl.close();
    }
});
