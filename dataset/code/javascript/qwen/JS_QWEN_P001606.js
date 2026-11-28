const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const nums = lines[1].split(/\s+/).map(Number);
        
        let map = {0: -1};
        let balance = 0;
        let count = 0;
        for (let i = 0; i < n; i++) {
            balance += (nums[i] === 0 ? -1 : 1);
            if (map[balance] !== undefined) count += (i - map[balance]); // This counts pairs, problem asks for subarrays? 
            // Actually standard problem is count subarrays.
            // Let's use standard prefix sum approach for equal 0s and 1s
            // Transform 0 to -1. Find subarrays with sum 0.
        }
        // Re-implementing correctly
        map = {0: 1};
        balance = 0;
        count = 0;
        for (let x of nums) {
            balance += (x === 0 ? -1 : 1);
            if (map[balance] !== undefined) count += map[balance];
            map[balance] = (map[balance] || 0) + 1;
        }
        console.log(count);
        rl.close();
    }
});
