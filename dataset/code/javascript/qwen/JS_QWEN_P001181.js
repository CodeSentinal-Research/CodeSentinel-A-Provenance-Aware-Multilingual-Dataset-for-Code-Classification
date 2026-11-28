const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const nums = lines[1].split(/\s+/).map(Number);
        let maxReach = 0;
        for(let i=0; i<n; i++) {
            if(i > maxReach) { console.log("NO"); rl.close(); return; }
            maxReach = Math.max(maxReach, i+nums[i]);
        }
        console.log("YES");
        rl.close();
    }
});
