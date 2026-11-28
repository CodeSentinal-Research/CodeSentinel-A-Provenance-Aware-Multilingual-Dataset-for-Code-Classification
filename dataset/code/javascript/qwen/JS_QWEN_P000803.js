const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === parseInt(lines[0].split(' ')[0]) + 2) {
        const [n, m] = lines[0].split(/\s+/).map(Number);
        let grid = [];
        for (let i = 1; i <= n; i++) grid.push(lines[i].split(/\s+/).map(Number));
        const target = parseInt(lines[n + 1]);
        
        let count = 0;
        // Fix top and bottom rows, then use 1D subarray sum equals K
        for (let r1 = 0; r1 < n; r1++) {
            let colSum = new Array(m).fill(0);
            for (let r2 = r1; r2 < n; r2++) {
                for (let c = 0; c < m; c++) colSum[c] += grid[r2][c];
                
                let map = {0: 1};
                let sum = 0;
                for (let c = 0; c < m; c++) {
                    sum += colSum[c];
                    if (map[sum - target] !== undefined) count += map[sum - target];
                    map[sum] = (map[sum] || 0) + 1;
                }
            }
        }
        console.log(count);
        rl.close();
    }
});
