const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 2) {
        const [rows, cols, threshold] = lines[0].split(/\s+/).map(Number);
        let grid = [];
        for (let i = 1; i <= rows; i++) grid.push(lines[i].split(/\s+/).map(Number));
        
        let prefix = Array(rows + 1).fill(0).map(() => Array(cols + 1).fill(0));
        for (let i = 1; i <= rows; i++) {
            for (let j = 1; j <= cols; j++) {
                prefix[i][j] = grid[i-1][j-1] + prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];
            }
        }
        
        let maxSide = 0;
        for (let side = 1; side <= Math.min(rows, cols); side++) {
            let found = false;
            for (let i = side; i <= rows; i++) {
                for (let j = side; j <= cols; j++) {
                    let sum = prefix[i][j] - prefix[i-side][j] - prefix[i][j-side] + prefix[i-side][j-side];
                    if (sum <= threshold) { found = true; break; }
                }
                if (found) break;
            }
            if (found) maxSide = side;
            else break;
        }
        console.log(maxSide);
        rl.close();
    }
});
