const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const [n, balls] = lines[0].split(/\s+/).map(Number);
        const position = lines[1].split(/\s+/).map(Number).sort((a,b)=>a-b);
        
        let l = 0, r = position[n-1] - position[0];
        while (l < r) {
            let mid = Math.ceil((l + r) / 2);
            let count = 1, last = position[0];
            for (let i = 1; i < n; i++) {
                if (position[i] - last >= mid) { count++; last = position[i]; }
            }
            if (count >= balls) l = mid;
            else r = mid - 1;
        }
        console.log(l);
        rl.close();
    }
});
