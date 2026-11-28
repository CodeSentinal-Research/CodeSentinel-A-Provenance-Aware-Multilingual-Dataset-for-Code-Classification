const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const [n, k] = lines[0].split(/\s+/).map(Number);
        const nums = lines[1].split(/\s+/).map(Number);
        
        let map = {0: 1};
        let sum = 0;
        let count = 0;
        for (let x of nums) {
            sum = ((sum + x) % k + k) % k;
            if (map[sum] !== undefined) count += map[sum];
            map[sum] = (map[sum] || 0) + 1;
        }
        console.log(count);
        rl.close();
    }
});
