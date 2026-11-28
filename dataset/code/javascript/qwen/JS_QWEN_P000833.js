const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const [n, students] = lines[0].split(/\s+/).map(Number);
        const pages = lines[1].split(/\s+/).map(Number);
        
        if (students > n) { console.log(-1); rl.close(); return; }
        
        let l = Math.max(...pages), r = pages.reduce((a,b)=>a+b, 0);
        while (l < r) {
            let mid = Math.floor((l + r) / 2);
            let s = 1, curr = 0;
            for (let p of pages) {
                if (curr + p > mid) { s++; curr = p; }
                else curr += p;
            }
            if (s > students) l = mid + 1;
            else r = mid;
        }
        console.log(l);
        rl.close();
    }
});
