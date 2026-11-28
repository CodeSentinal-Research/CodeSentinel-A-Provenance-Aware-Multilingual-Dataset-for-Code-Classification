const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const nums = lines[1].split(/\s+/).map(Number);
        
        let total = nums.reduce((a,b)=>a+b, 0);
        if (total % 3 !== 0) { console.log(0); rl.close(); return; }
        
        let target = total / 3;
        let count1 = 0;
        let count2 = 0;
        let sum = 0;
        
        for (let i = 0; i < n - 1; i++) {
            sum += nums[i];
            if (sum === 2 * target) count2 += count1;
            if (sum === target) count1++;
        }
        console.log(count2);
        rl.close();
    }
});
