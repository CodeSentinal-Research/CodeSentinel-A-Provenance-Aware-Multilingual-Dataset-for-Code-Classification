const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const nums = lines[1].split(/\s+/).map(Number);
        
        let stack = [], chunks=0;
        let maxSeen = -Infinity;
        for(let i=0; i<n; i++) {
            maxSeen = Math.max(maxSeen, nums[i]);
            while(stack.length && stack[stack.length-1]>nums[i]) stack.pop();
            stack.push(maxSeen);
            if(stack.length===1 && stack[0]===nums[i]) chunks++; // Simplified logic
        }
        console.log(chunks);
        rl.close();
    }
});
