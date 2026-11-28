const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const nums = lines[1].split(/\s+/).map(Number);
        let g = nums[0];
        for (let i = 1; i < n; i++) {
            function gcd(a, b) { return b === 0 ? a : gcd(b, a % b); }
            g = gcd(g, nums[i]);
        }
        console.log(g);
        rl.close();
    }
});
