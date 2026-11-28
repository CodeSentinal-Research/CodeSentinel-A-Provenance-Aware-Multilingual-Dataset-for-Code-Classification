const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const nums = lines[1].split(/\s+/).map(Number).sort((a,b)=>a-b);
        
        let res = [];
        function permute(curr, used) {
            if(curr.length===n) { res.push(curr.slice()); return; }
            for(let i=0; i<n; i++) {
                if(used[i] || (i>0 && nums[i]===nums[i-1] && !used[i-1])) continue;
                used[i] = true;
                curr.push(nums[i]);
                permute(curr, used);
                curr.pop();
                used[i] = false;
            }
        }
        permute([], new Array(n).fill(false));
        console.log(res.map(r=>r.join(" ")).join("\n"));
        rl.close();
    }
});
