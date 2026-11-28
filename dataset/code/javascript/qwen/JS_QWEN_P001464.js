const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const nums = lines[1].split(/\s+/).map(Number);
        
        let j = 0;
        for (let i = 0; i < n; i++) {
            if (nums[i] !== 0) {
                [nums[i], nums[j]] = [nums[j], nums[i]];
                j++;
            }
        }
        console.log(nums.join(" "));
        rl.close();
    }
});
