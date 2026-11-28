const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const [n, m, k] = lines[0].split(/\s+/).map(Number);
        const bloomDay = lines[1].split(/\s+/).map(Number);
        
        if (m * k > n) { console.log(-1); rl.close(); return; }
        
        let l = 1, r = Math.max(...bloomDay);
        while (l < r) {
            let mid = Math.floor((l + r) / 2);
            let bouquets = 0, flowers = 0;
            for (let b of bloomDay) {
                if (b <= mid) flowers++;
                else flowers = 0;
                if (flowers === k) { bouquets++; flowers = 0; }
            }
            if (bouquets < m) l = mid + 1;
            else r = mid;
        }
        console.log(l);
        rl.close();
    }
});
