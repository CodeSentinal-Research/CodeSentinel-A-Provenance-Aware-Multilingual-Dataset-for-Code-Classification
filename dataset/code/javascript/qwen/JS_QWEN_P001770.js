const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 3) {
        const [n, m] = lines[0].split(/\s+/).map(Number);
        let grid = [];
        for (let i = 1; i <= n; i++) grid.push(lines[i].split(/\s+/).map(Number));
        
        let count = 0;
        function solve(r, c) {
            if (r === n-1 && c === m-1) {
                count++;
                return;
            }
            if (r+1 < n && grid[r+1][c] === 1) solve(r+1, c);
            if (c+1 < m && grid[r][c+1] === 1) solve(r, c+1);
        }
        if (grid[0][0] === 1) solve(0, 0);
        console.log(count);
        rl.close();
    }
});
