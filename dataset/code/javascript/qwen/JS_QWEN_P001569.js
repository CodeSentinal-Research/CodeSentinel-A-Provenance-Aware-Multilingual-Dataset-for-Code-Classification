const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const nums = lines[1].split(/\s+/).map(Number);
        
        let maxLen = 0;
        let negCount = 0;
        let posCount = 0;
        let lastNeg = -1;
        let lastZero = -1;
        
        for (let i = 0; i < n; i++) {
            if (nums[i] < 0) {
                negCount++;
                lastNeg = i;
            } else if (nums[i] === 0) {
                negCount = 0;
                posCount = 0;
                lastZero = i;
            } else {
                posCount++;
            }
            
            if (negCount % 2 === 0) {
                maxLen = Math.max(maxLen, i - lastZero);
            } else {
                maxLen = Math.max(maxLen, i - lastNeg);
            }
        }
        
        console.log(maxLen);
        rl.close();
    }
});
