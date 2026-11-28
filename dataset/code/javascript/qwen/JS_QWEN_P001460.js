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
        let xor = 0;
        for (let x of nums) {
            xor ^= x;
            if (map[xor]) count += map[xor];
            map[xor] = (map[xor] || 0) + 1;
        }
        // This counts subarrays with XOR 0. Problem asks for pairs of prefixes.
        // Re-reading problem: Count pairs (i,j) such that prefixXOR[i] == prefixXOR[j].
        // This is equivalent to sum of C(val, 2) for each frequency val in map.
        // Also include 0 if it appears.
        let res = 0;
        for (let k in map) {
            let v = map[k];
            res += (v * (v - 1)) / 2;
        }
        console.log(res);
        rl.close();
    }
});
