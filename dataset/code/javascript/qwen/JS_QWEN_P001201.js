const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === parseInt(lines[0]) + 1) {
        const n = parseInt(lines[0]);
        const grid = [];
        for(let i=1; i<=n; i++) grid.push(lines[i].split(/\s+/).map(Number));
        
        let dp = Array.from({length: n}, () => new Array(n).fill(Infinity));
        dp[0][0] = grid[0][0];
        
        // Standard DP for min path sum with constraints? 
        // Problem says "Minimum Falling Path Sum II" -> No two consecutive elements in same column.
        // Let's assume standard falling path but with constraint.
        // Actually, P001201 is usually "Minimum Falling Path Sum II" from LeetCode which is N x N grid, pick one from each row, no two from same col.
        
        let prevMin = [], prevSecMin = [];
        // Initialize for first row
        let min1 = Infinity, min2 = Infinity, idx1 = -1;
        for(let j=0; j<n; j++) {
            if(grid[0][j] < min1) { min2 = min1; min1 = grid[0][j]; idx1 = j; }
            else if(grid[0][j] < min2) { min2 = grid[0][j]; }
        }
        
        let currRow = [...grid[0]];
        
        for(let i=1; i<n; i++) {
            let newMin1 = Infinity, newMin2 = Infinity, newIdx1 = -1;
            let nextRow = new Array(n);
            for(let j=0; j<n; j++) {
                let bestPrev = (j === idx1) ? min2 : min1;
                nextRow[j] = grid[i][j] + bestPrev;
                
                if(nextRow[j] < newMin1) { newMin2 = newMin1; newMin1 = nextRow[j]; newIdx1 = j; }
                else if(nextRow[j] < newMin2) { newMin2 = nextRow[j]; }
            }
            min1 = newMin1; min2 = newMin2; idx1 = newIdx1;
            currRow = nextRow;
        }
        console.log(min1);
        rl.close();
    }
});
