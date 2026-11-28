const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 2) {
        const [rows, cols, k] = lines[0].split(/\s+/).map(Number);
        let grid = [];
        for (let i = 1; i <= rows; i++) grid.push(lines[i].split(/\s+/).map(Number));
        
        let maxArea = 0;
        // Iterate over all pairs of columns
        for (let l = 0; l < cols; l++) {
            let temp = new Array(rows).fill(0);
            for (let r = l; r < cols; r++) {
                for (let i = 0; i < rows; i++) temp[i] += grid[i][r];
                
                // Find largest rectangle in histogram temp with sum <= k
                // This is hard. Usually max sum rectangle <= k is O(N^3 log N) or similar.
                // For small constraints, we can check all subarrays of temp
                for (let i = 0; i < rows; i++) {
                    let sum = 0;
                    for (let j = i; j < rows; j++) {
                        sum += temp[j];
                        if (sum <= k) {
                            maxArea = Math.max(maxArea, (j - i + 1) * (r - l + 1));
                        }
                    }
                }
            }
        }
        console.log(maxArea);
        rl.close();
    }
});
