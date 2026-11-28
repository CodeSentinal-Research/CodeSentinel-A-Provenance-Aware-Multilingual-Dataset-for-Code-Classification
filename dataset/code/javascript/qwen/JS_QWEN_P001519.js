const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const nums = lines[1].split(/\s+/).map(Number);
        
        let maxLen = 1;
        let currLen = 1;
        
        for (let i = 1; i < n; i++) {
            if (nums[i] > nums[i-1]) {
                currLen++;
                maxLen = Math.max(maxLen, currLen);
            } else {
                currLen = 1;
            }
        }
        
        console.log(maxLen);
        rl.close();
    }
});
