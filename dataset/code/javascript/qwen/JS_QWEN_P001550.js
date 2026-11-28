const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const [n, k] = lines[0].split(/\s+/).map(Number);
        const nums = lines[1].split(/\s+/).map(Number);
        
        let res = [];
        let sumDiff = 0;
        
        for (let i = 1; i < k; i++) {
            sumDiff += Math.abs(nums[i] - nums[i-1]);
        }
        res.push(sumDiff);
        
        for (let i = k; i < n; i++) {
            sumDiff -= Math.abs(nums[i - k + 1] - nums[i - k]);
            sumDiff += Math.abs(nums[i] - nums[i - 1]);
            res.push(sumDiff);
        }
        
        console.log(res.join(" "));
        rl.close();
    }
});
