const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const [n, target] = lines[0].split(/\s+/).map(Number);
        const nums = lines[1].split(/\s+/).map(Number);
        
        let map = {0: -1}, sum = 0, maxLen = 0;
        for (let i = 0; i < n; i++) {
            sum += nums[i];
            if (map[sum - target] !== undefined) maxLen = Math.max(maxLen, i - map[sum - target]);
            if (map[sum] === undefined) map[sum] = i;
        }
        console.log(maxLen);
        rl.close();
    }
});
