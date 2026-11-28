const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const [n, maxOps] = lines[0].split(/\s+/).map(Number);
        const nums = lines[1].split(/\s+/).map(Number);
        
        let l = 1, r = Math.max(...nums);
        while (l < r) {
            let mid = Math.floor((l + r) / 2);
            let ops = 0;
            for (let x of nums) ops += Math.floor((x - 1) / mid);
            if (ops > maxOps) l = mid + 1;
            else r = mid;
        }
        console.log(l);
        rl.close();
    }
});
