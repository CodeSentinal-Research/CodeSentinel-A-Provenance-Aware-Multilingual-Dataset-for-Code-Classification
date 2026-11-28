const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= parseInt(lines[0]) + 2) {
        const [n, m] = lines[0].split(/\s+/).map(Number);
        let grid = [];
        for (let i = 1; i <= n; i++) grid.push(lines[i].split(/\s+/).map(Number));
        const q = parseInt(lines[n + 1]);
        let prefix = Array(n + 1).fill(0).map(() => Array(m + 1).fill(0));
        for (let i = 1; i <= n; i++) {
            for (let j = 1; j <= m; j++) {
                prefix[i][j] = grid[i - 1][j - 1] + prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1];
            }
        }
        let res = [];
        for (let i = n + 2; i < n + 2 + q; i++) {
            let [r1, c1, r2, c2] = lines[i].split(/\s+/).map(Number);
            r1++; c1++; r2++; c2++;
            let sum = prefix[r2][c2] - prefix[r1 - 1][c2] - prefix[r2][c1 - 1] + prefix[r1 - 1][c1 - 1];
            res.push(sum);
        }
        console.log(res.join("\n"));
        rl.close();
    }
});
