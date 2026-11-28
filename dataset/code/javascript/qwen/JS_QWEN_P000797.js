const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const arr = lines[1].split(/\s+/).map(Number);
        let map = {0: 1}, sum = 0, count = 0;
        for (let x of arr) {
            sum += x === 0 ? -1 : 1;
            if (map[sum] !== undefined) count += map[sum];
            map[sum] = (map[sum] || 0) + 1;
        }
        console.log(count);
        rl.close();
    }
});
