const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 3) {
        const n = parseInt(lines[0]);
        const nums = lines[1].split(/\s+/).map(Number);
        const [l, r] = lines[2].split(/\s+/).map(Number);
        
        let sum = 0;
        for (let i = l; i <= r; i++) sum += nums[i];
        
        console.log(sum);
        rl.close();
    }
});
