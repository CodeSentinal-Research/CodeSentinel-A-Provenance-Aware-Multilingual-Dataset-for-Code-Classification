const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const nums = lines[1].split(/\s+/).map(Number);
        
        let map = {0: 1};
        let balance = 0;
        let count = 0;
        for (let x of nums) {
            balance += (x > 0 ? 1 : -1);
            if (map[balance] !== undefined) count += map[balance];
            map[balance] = (map[balance] || 0) + 1;
        }
        console.log(count);
        rl.close();
    }
});
