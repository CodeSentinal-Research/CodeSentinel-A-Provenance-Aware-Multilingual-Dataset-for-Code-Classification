const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 3) {
        const n = parseInt(lines[0]);
        const arr = lines[1].split(/\s+/).map(Number);
        const k = parseInt(lines[2]);
        let map = {0: -1}, sum = 0, found = false;
        for (let i = 0; i < n; i++) {
            sum += arr[i];
            if (k !== 0) {
                if (map[sum % k] !== undefined && i - map[sum % k] > 1) { found = true; break; }
            } else {
                if (map[sum] !== undefined && i - map[sum] > 1) { found = true; break; }
            }
            if (map[sum % k] === undefined) map[sum % k] = i;
        }
        console.log(found ? "true" : "false");
        rl.close();
    }
});
