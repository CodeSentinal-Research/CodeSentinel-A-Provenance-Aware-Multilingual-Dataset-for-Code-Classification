const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 3) {
        const n = parseInt(lines[0]);
        const arr = lines[1].split(/\s+/).map(Number);
        const k = parseInt(lines[2]);
        let map = {0: -1}, sum = 0, maxLen = 0;
        for (let i = 0; i < n; i++) {
            sum += arr[i];
            if (map[sum - k] !== undefined) maxLen = Math.max(maxLen, i - map[sum - k]);
            if (map[sum] === undefined) map[sum] = i;
        }
        console.log(maxLen);
        rl.close();
    }
});
