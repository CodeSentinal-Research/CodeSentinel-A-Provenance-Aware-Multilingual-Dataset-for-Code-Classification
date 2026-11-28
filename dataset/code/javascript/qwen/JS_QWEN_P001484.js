const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const nums = lines[1].split(/\s+/).map(Number);
        
        let maxLen = 0, inc = 1, dec = 1;
        for (let i = 1; i < n; i++) {
            if (nums[i] > nums[i-1]) {
                inc = dec + 1;
                dec = 1;
            } else if (nums[i] < nums[i-1]) {
                dec = inc + 1;
                inc = 1;
            } else {
                inc = 1; dec = 1;
            }
            maxLen = Math.max(maxLen, inc, dec);
        }
        console.log(maxLen);
        rl.close();
    }
});
