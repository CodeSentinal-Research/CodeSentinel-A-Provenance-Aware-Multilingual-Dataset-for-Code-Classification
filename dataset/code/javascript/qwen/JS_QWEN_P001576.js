const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const [n, k] = lines[0].split(/\s+/).map(Number);
        const nums = lines[1].split(/\s+/).map(Number);
        
        let count = 0;
        let hasZero = false;
        for (let i = 0; i < k; i++) {
            if (nums[i] === 0) hasZero = true;
        }
        if (hasZero) count++;
        
        for (let i = k; i < n; i++) {
            if (nums[i] === 0) hasZero = true;
            if (nums[i - k] === 0) {
                hasZero = false;
                for (let j = i - k + 1; j <= i; j++) {
                    if (nums[j] === 0) {
                        hasZero = true;
                        break;
                    }
                }
            }
            if (hasZero) count++;
        }
        
        console.log(count);
        rl.close();
    }
});
