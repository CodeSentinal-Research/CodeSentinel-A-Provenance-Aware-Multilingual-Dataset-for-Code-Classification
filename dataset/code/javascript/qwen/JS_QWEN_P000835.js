const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const [n, cows] = lines[0].split(/\s+/).map(Number);
        const stalls = lines[1].split(/\s+/).map(Number).sort((a,b)=>a-b);
        
        let l = 0, r = stalls[n-1] - stalls[0];
        while (l < r) {
            let mid = Math.ceil((l + r) / 2);
            let count = 1, last = stalls[0];
            for (let i = 1; i < n; i++) {
                if (stalls[i] - last >= mid) { count++; last = stalls[i]; }
            }
            if (count >= cows) l = mid;
            else r = mid - 1;
        }
        console.log(l);
        rl.close();
    }
});
