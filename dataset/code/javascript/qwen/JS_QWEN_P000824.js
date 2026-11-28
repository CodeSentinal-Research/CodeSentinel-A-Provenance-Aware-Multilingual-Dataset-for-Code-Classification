const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 2) {
        const [n, m, target] = lines[0].split(/\s+/).map(Number);
        let matrix = [];
        for (let i = 1; i <= n; i++) matrix.push(lines[i].split(/\s+/).map(Number));
        
        let l = 0, r = n * m - 1;
        while (l <= r) {
            let mid = Math.floor((l + r) / 2);
            let val = matrix[Math.floor(mid / m)][mid % m];
            if (val === target) { console.log("true"); rl.close(); return; }
            else if (val < target) l = mid + 1;
            else r = mid - 1;
        }
        console.log("false");
        rl.close();
    }
});
