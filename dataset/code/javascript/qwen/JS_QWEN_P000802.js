const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === parseInt(lines[0].split(' ')[0]) + 2) {
        const [n, m] = lines[0].split(/\s+/).map(Number);
        let grid = [];
        for (let i = 1; i <= n; i++) grid.push(lines[i].split(/\s+/).map(Number));
        const threshold = parseInt(lines[n + 1]);
        
        let prefix = Array(n + 1).fill(0).map(() => Array(m + 1).fill(0));
        for (let i = 1; i <= n; i++) {
            for (let j = 1; j <= m; j++) {
                prefix[i][j] = grid[i - 1][j - 1] + prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1];
            }
        }
        
        let maxSide = 0;
        for (let side = 1; side <= Math.min(n, m); side++) {
            let found = false;
            for (let i = side; i <= n; i++) {
                for (let j = side; j <= m; j++) {
                    let sum = prefix[i][j] - prefix[i - side][j] - prefix[i][j - side] + prefix[i - side][j - side];
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
