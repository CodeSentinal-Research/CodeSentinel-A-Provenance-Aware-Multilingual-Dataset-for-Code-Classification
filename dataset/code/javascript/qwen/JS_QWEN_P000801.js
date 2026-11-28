const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === parseInt(lines[0].split(' ')[0]) + 2) {
        const [n, m] = lines[0].split(/\s+/).map(Number);
        let grid = [];
        for (let i = 1; i <= n; i++) grid.push(lines[i].split(/\s+/).map(Number));
        const k = parseInt(lines[n + 1]);
        
        // Compute 2D prefix sum
        let prefix = Array(n + 1).fill(0).map(() => Array(m + 1).fill(0));
        for (let i = 1; i <= n; i++) {
            for (let j = 1; j <= m; j++) {
                prefix[i][j] = grid[i - 1][j - 1] + prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1];
            }
        }
        
        let res = Array(n).fill(0).map(() => Array(m).fill(0));
        for (let i = 1; i <= n; i++) {
            for (let j = 1; j <= m; j++) {
                let r1 = Math.max(1, i - k);
                let c1 = Math.max(1, j - k);
                let r2 = Math.min(n, i + k);
                let c2 = Math.min(m, j + k);
                res[i - 1][j - 1] = prefix[r2][c2] - prefix[r1 - 1][c2] - prefix[r2][c1 - 1] + prefix[r1 - 1][c1 - 1];
            }
        }
        res.forEach(row => console.log(row.join(" ")));
        rl.close();
    }
});
