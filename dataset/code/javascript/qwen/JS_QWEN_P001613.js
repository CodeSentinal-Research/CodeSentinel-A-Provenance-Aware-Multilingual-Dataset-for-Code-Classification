const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 2) {
        const [rows, cols, k] = lines[0].split(/\s+/).map(Number);
        let grid = [];
        for (let i = 1; i <= rows; i++) grid.push(lines[i].split(/\s+/).map(Number));
        
        let prefix = Array(rows + 1).fill(0).map(() => Array(cols + 1).fill(0));
        for (let i = 1; i <= rows; i++) {
            for (let j = 1; j <= cols; j++) {
                prefix[i][j] = grid[i-1][j-1] + prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];
            }
        }
        
        let res = Array(rows).fill(0).map(() => Array(cols).fill(0));
        for (let i = 0; i < rows; i++) {
            for (let j = 0; j < cols; j++) {
                let r1 = Math.max(0, i - k);
                let c1 = Math.max(0, j - k);
                let r2 = Math.min(rows - 1, i + k);
                let c2 = Math.min(cols - 1, j + k);
                
                // Convert to 1-based for prefix
                r1++; c1++; r2++; c2++;
                
                res[i][j] = prefix[r2][c2] - prefix[r1-1][c2] - prefix[r2][c1-1] + prefix[r1-1][c1-1];
            }
        }
        res.forEach(row => console.log(row.join(" ")));
        rl.close();
    }
});
