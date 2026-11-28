const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 2) {
        const [rows, cols, target] = lines[0].split(/\s+/).map(Number);
        let grid = [];
        for (let i = 1; i <= rows; i++) grid.push(lines[i].split(/\s+/).map(Number));
        
        let count = 0;
        for (let l = 0; l < cols; l++) {
            let temp = new Array(rows).fill(0);
            for (let r = l; r < cols; r++) {
                for (let i = 0; i < rows; i++) temp[i] += grid[i][r];
                
                // Count subarrays with sum target in temp
                let map = {0: 1};
                let sum = 0;
                for (let x of temp) {
                    sum += x;
                    if (map[sum - target] !== undefined) count += map[sum - target];
                    map[sum] = (map[sum] || 0) + 1;
                }
            }
        }
        console.log(count);
        rl.close();
    }
});
