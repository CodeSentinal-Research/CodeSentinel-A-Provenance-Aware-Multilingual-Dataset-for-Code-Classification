const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const nums = lines[1].split(/\s+/).map(Number);
        const k = parseInt(lines[0].split(' ')[1]); // Wait, input format says N and K on first line? No, problem says Integer n, Array, Integer K.
        // Re-reading P000804: Input: Integer n, Array nums, Integer K.
        // Let's assume standard format: Line 1: N K, Line 2: Array
        const parts = lines[0].split(/\s+/);
        const N = parseInt(parts[0]);
        const K = parseInt(parts[1]);
        const arr = lines[1].split(/\s+/).map(Number);
        
        let map = {0: 1};
        let xor = 0;
        let count = 0;
        for (let x of arr) {
            xor ^= x;
            if (map[xor ^ K] !== undefined) count += map[xor ^ K];
            map[xor] = (map[xor] || 0) + 1;
        }
        console.log(count);
        rl.close();
    }
});
