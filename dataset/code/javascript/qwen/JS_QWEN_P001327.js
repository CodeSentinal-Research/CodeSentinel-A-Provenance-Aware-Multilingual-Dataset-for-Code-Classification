const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const nums = lines[1].split(/\s+/).map(Number).sort((a,b)=>a-b);
        
        let res = [];
        function subs(i, curr) {
            res.push(curr.slice());
            for(let j=i; j<n; j++) {
                if(j>i && nums[j]===nums[j-1]) continue;
                curr.push(nums[j]);
                subs(j+1, curr);
                curr.pop();
            }
        }
        subs(0, []);
        console.log(res.map(r=>r.join(" ")).join("\n"));
        rl.close();
    }
});
