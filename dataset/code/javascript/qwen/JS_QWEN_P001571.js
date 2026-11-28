const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const [n, k] = lines[0].split(/\s+/).map(Number);
        const nums = lines[1].split(/\s+/).map(Number);
        
        let res = [];
        for (let i = 0; i <= n - k; i++) {
            res.push(nums[i + k - 1] - nums[i]);
        }
        
        console.log(res.join(" "));
        rl.close();
    }
});
