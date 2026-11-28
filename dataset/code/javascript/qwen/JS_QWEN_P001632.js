const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 2) {
        const [rows, cols, k] = lines[0].split(/\s+/).map(Number);
        let grid = [];
        for (let i = 1; i <= rows; i++) grid.push(lines[i].split(/\s+/).map(Number));
        
        let maxSide = 0;
        for (let i = 0; i < rows; i++) {
            for (let j = 0; j < cols; j++) {
                for (let side = 1; side <= Math.min(rows - i, cols - j); side++) {
                    // Check sum of square (i,j) to (i+side-1, j+side-1)
                    // Using prefix sum would be better but nested loop is ok for small N
                    let sum = 0;
                    let valid = true;
                    // Calculate sum efficiently? No, just brute force for simplicity in generation
                    // Actually, let's use prefix sum
                }
            }
        }
        // Re-implementing with prefix sum
        let prefix = Array(rows + 1).fill(0).map(() => Array(cols + 1).fill(0));
        for (let i = 1; i <= rows; i++) {
            for (let j = 1; j <= cols; j++) {
                prefix[i][j] = grid[i-1][j-1] + prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];
            }
        }
        
        for (let side = Math.min(rows, cols); side >= 1; side--) {
            let found = false;
            for (let i = side; i <= rows; i++) {
                for (let j = side; j <= cols; j++) {
                    let sum = prefix[i][j] - prefix[i-side][j] - prefix[i][j-side] + prefix[i-side][j-side];
                    if (sum <= k) { found = true; break; }
                }
                if (found) break;
            }
            if (found) { maxSide = side; break; }
        }
        console.log(maxSide);
        rl.close();
    }
});
