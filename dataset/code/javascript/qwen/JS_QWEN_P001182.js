const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const nums = lines[1].split(/\s+/).map(Number);
        let jumps=0, currentEnd=0, farthest=0;
        for(let i=0; i<n-1; i++) {
            farthest = Math.max(farthest, i+nums[i]);
            if(i===currentEnd) {
                jumps++;
                currentEnd = farthest;
            }
        }
        console.log(jumps);
        rl.close();
    }
});
