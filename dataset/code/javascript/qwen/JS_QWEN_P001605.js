const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const [n, k] = lines[0].split(/\s+/).map(Number);
        const nums = lines[1].split(/\s+/).map(Number);
        
        let map = {};
        let sum = 0;
        let maxLen = 0;
        for (let i = 0; i < n; i++) {
            sum += nums[i];
            if (sum === k) maxLen = i + 1;
            if (map[sum - k] !== undefined) {
                maxLen = Math.max(maxLen, i - map[sum - k]);
            }
            if (map[sum] === undefined) map[sum] = i;
        }
        console.log(maxLen);
        rl.close();
    }
});
