const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const nums = lines[1].split(/\s+/).map(Number);
        
        nums.sort((a,b)=>a-b);
        let minDiff = Infinity;
        for(let i=1; i<n; i++) minDiff = Math.min(minDiff, nums[i]-nums[i-1]);
        
        let res = [];
        for(let i=1; i<n; i++) {
            if(nums[i]-nums[i-1]===minDiff) res.push(`${nums[i-1]} ${nums[i]}`);
        }
        console.log(res.join("\n"));
        rl.close();
    }
});
