const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const [n, k] = lines[0].split(/\s+/).map(Number);
        const nums = lines[1].split(/\s+/).map(Number);
        
        let count = 0;
        let sum = 0;
        for (let i = 0; i < k; i++) sum += nums[i];
        if (sum % 2 === 0) count++;
        
        for (let i = k; i < n; i++) {
            sum += nums[i] - nums[i - k];
            if (sum % 2 === 0) count++;
        }
        
        console.log(count);
        rl.close();
    }
});
