const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 3 + parseInt(lines[2])) {
        const [rows, cols] = lines[0].split(/\s+/).map(Number);
        let grid = [];
        for (let i = 1; i <= rows; i++) grid.push(lines[i].split(/\s+/).map(Number));
        
        const q = parseInt(lines[rows + 1]);
        
        let prefix = Array(rows + 1).fill(0).map(() => Array(cols + 1).fill(0));
        for (let i = 1; i <= rows; i++) {
            for (let j = 1; j <= cols; j++) {
                prefix[i][j] = grid[i-1][j-1] + prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];
            }
        }
        
        let res = [];
        for (let i = rows + 2; i < rows + 2 + q; i++) {
            const [r1, c1, r2, c2] = lines[i].split(/\s+/).map(Number);
            // Convert to 1-based
            let sum = prefix[r2+1][c2+1] - prefix[r1][c2+1] - prefix[r2+1][c1] + prefix[r1][c1];
            res.push(sum);
        }
        console.log(res.join("\n"));
        rl.close();
    }
});
