const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const [n, painters] = lines[0].split(/\s+/).map(Number);
        const boards = lines[1].split(/\s+/).map(Number);
        
        let l = Math.max(...boards), r = boards.reduce((a,b)=>a+b, 0);
        while (l < r) {
            let mid = Math.floor((l + r) / 2);
            let p = 1, curr = 0;
            for (let b of boards) {
                if (curr + b > mid) { p++; curr = b; }
                else curr += b;
            }
            if (p > painters) l = mid + 1;
            else r = mid;
        }
        console.log(l);
        rl.close();
    }
});
