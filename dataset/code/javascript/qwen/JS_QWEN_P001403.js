const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 2) {
        const [n, q] = lines[0].split(/\s+/).map(Number);
        const nums = lines[1].split(/\s+/).map(Number);
        
        let res = [];
        for (let i = 2; i < 2 + q; i++) {
            const [l, r] = lines[i].split(/\s+/).map(Number);
            let sub = nums.slice(l, r + 1).sort((a,b)=>a-b);
            let isArith = true;
            if (sub.length > 2) {
                let diff = sub[1] - sub[0];
                for (let j = 2; j < sub.length; j++) {
                    if (sub[j] - sub[j-1] !== diff) { isArith = false; break; }
                }
            }
            res.push(isArith ? "YES" : "NO");
        }
        console.log(res.join("\n"));
        rl.close();
    }
});
