const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const nums = lines[1].split(/\s+/).map(Number);
        
        if(n===0) { console.log(0); rl.close(); return; }
        let up=1, down=1;
        for(let i=1; i<n; i++) {
            if(nums[i] > nums[i-1]) up = down+1;
            else if(nums[i] < nums[i-1]) down = up+1;
        }
        console.log(Math.max(up, down));
        rl.close();
    }
});
