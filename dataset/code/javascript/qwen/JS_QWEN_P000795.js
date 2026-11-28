const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 3) {
        const n = parseInt(lines[0]);
        const arr = lines[1].split(/\s+/).map(Number);
        const k = parseInt(lines[2]);
        let map = {0: 1}, sum = 0, count = 0;
        for (let x of arr) {
            sum = (sum + x) % k;
            if (sum < 0) sum += k;
            if (map[sum] !== undefined) count += map[sum];
            map[sum] = (map[sum] || 0) + 1;
        }
        console.log(count);
        rl.close();
    }
});
