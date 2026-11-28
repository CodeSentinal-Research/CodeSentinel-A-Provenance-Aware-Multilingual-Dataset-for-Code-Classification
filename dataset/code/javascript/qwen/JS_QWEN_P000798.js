const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const arr = lines[1].split(/\s+/).map(Number);
        let map = {0: -1}, sum = 0, maxLen = 0;
        for (let i = 0; i < n; i++) {
            sum += arr[i] === 0 ? -1 : 1;
            if (map[sum] !== undefined) maxLen = Math.max(maxLen, i - map[sum]);
            else map[sum] = i;
        }
        console.log(maxLen);
        rl.close();
    }
});
