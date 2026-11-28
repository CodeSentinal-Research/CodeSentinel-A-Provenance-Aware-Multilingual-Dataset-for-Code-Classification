const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === parseInt(lines[0]) + 1) {
        const [n, m] = lines[0].split(/\s+/).map(Number);
        let grid = [];
        for (let i = 1; i <= n; i++) grid.push(lines[i].split(/\s+/).map(Number));
        let res = [];
        function solve(r, c, path) {
            if (r === n - 1 && c === m - 1) {
                res.push(path);
                return;
            }
            grid[r][c] = 0;
            if (r + 1 < n && grid[r + 1][c] === 1) solve(r + 1, c, path + "D");
            if (c + 1 < m && grid[r][c + 1] === 1) solve(r, c + 1, path + "R");
            if (r - 1 >= 0 && grid[r - 1][c] === 1) solve(r - 1, c, path + "U");
            if (c - 1 >= 0 && grid[r][c - 1] === 1) solve(r, c - 1, path + "L");
            grid[r][c] = 1;
        }
        if (grid[0][0] === 1) solve(0, 0, "");
        console.log(res.join("\n"));
        rl.close();
    }
});
