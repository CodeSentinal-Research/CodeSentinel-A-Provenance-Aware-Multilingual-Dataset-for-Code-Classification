const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const [n, k] = lines[0].split(/\s+/).map(Number);
        const price = lines[1].split(/\s+/).map(Number).sort((a,b)=>a-b);
        
        let l = 0, r = price[n-1] - price[0];
        while (l < r) {
            let mid = Math.ceil((l + r) / 2);
            let count = 1, last = price[0];
            for (let i = 1; i < n; i++) {
                if (price[i] - last >= mid) { count++; last = price[i]; }
            }
            if (count >= k) l = mid;
            else r = mid - 1;
        }
        console.log(l);
        rl.close();
    }
});
