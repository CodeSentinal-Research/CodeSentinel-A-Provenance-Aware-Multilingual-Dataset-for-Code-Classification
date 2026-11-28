const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 2) {
        const [rows, cols] = lines[0].split(/\s+/).map(Number);
        let grid = [];
        for (let i = 1; i <= rows; i++) grid.push(lines[i].split(/\s+/).map(Number));
        
        let maxSum = -Infinity;
        for (let l = 0; l < cols; l++) {
            let temp = new Array(rows).fill(0);
            for (let r = l; r < cols; r++) {
                for (let i = 0; i < rows; i++) temp[i] += grid[i][r];
                
                // Kadane's on temp
                let currentMax = temp[0];
                let globalMax = temp[0];
                for (let i = 1; i < rows; i++) {
                    currentMax = Math.max(temp[i], currentMax + temp[i]);
                    globalMax = Math.max(globalMax, currentMax);
                }
                maxSum = Math.max(maxSum, globalMax);
            }
        }
        console.log(maxSum);
        rl.close();
    }
});
