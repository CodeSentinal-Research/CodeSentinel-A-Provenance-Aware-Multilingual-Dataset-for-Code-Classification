const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const nums = lines[1].split(/\s+/).map(Number);
        
        let res = [];
        function subs(i, curr) {
            if(i===n) { res.push(curr.slice()); return; }
            subs(i+1, curr);
            curr.push(nums[i]);
            subs(i+1, curr);
            curr.pop();
        }
        subs(0, []);
        console.log(res.map(r=>r.join(" ")).join("\n"));
        rl.close();
    }
});
