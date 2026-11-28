const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const nums = lines[1].split(/\s+/).map(Number);
        
        let res = [];
        function solve(i, curr, sum) {
            if(i===n) {
                if(sum===0) res.push(curr.slice());
                return;
            }
            // Include positive
            if(nums[i]>0) {
                curr.push(nums[i]);
                solve(i+1, curr, sum+nums[i]);
                curr.pop();
            }
            // Include negative
            if(nums[i]<0) {
                curr.push(nums[i]);
                solve(i+1, curr, sum+nums[i]);
                curr.pop();
            }
            // Skip
            solve(i+1, curr, sum);
        }
        solve(0, [], 0);
        console.log(res.map(r=>r.join(" ")).join("\n"));
        rl.close();
    }
});
