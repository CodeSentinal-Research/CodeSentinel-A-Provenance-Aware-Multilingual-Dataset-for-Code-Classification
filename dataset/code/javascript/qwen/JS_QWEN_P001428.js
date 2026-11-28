const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const nums = lines[1].split(/\s+/).map(Number);
        
        let map = {};
        let count = 0;
        let mod = 10**9 + 7;
        for (let x of nums) {
            for (let p = 1; p <= 2**22; p *= 2) {
                if (map[p - x]) count = (count + map[p - x]) % mod;
            }
            map[x] = (map[x] || 0) + 1;
        }
        console.log(count);
        rl.close();
    }
});
