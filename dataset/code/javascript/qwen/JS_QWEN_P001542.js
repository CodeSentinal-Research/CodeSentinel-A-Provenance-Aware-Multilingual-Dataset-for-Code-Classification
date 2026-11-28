const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const [n, k] = lines[0].split(/\s+/).map(Number);
        const nums = lines[1].split(/\s+/).map(Number);
        
        let sum = 0;
        for (let i = 0; i < k; i++) sum += nums[i];
        
        let res = [(sum / k).toFixed(1)];
        for (let i = k; i < n; i++) {
            sum += nums[i] - nums[i - k];
            res.push((sum / k).toFixed(1));
        }
        
        console.log(res.join(" "));
        rl.close();
    }
});
