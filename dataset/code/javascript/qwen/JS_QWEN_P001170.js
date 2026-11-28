const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 2) {
        const n = parseInt(lines[0]);
        let grid = [];
        for(let i=1; i<=n; i++) grid.push(lines[i].split(/\s+/).map(Number));
        let dp = Array.from({length:n}, ()=>Array.from({length:n}, ()=>Array.from({length:n}, ()=>Array.from({length:n}, ()=>-1))));
        
        function dfs(r1, c1, r2, c2) {
            if(r1>=n || c1>=n || r2>=n || c2>=n || grid[r1][c1]===-1 || grid[r2][c2]===-1) return -Infinity;
            if(dp[r1][c1][r2][c2] !== -1) return dp[r1][c1][r2][c2];
            if(r1===n-1 && c1===n-1) return grid[r1][c1];
            
            let cherries = grid[r1][c1];
            if(r1!==r2 || c1!==c2) cherries += grid[r2][c2];
            
            let maxNext = -Infinity;
            maxNext = Math.max(maxNext, dfs(r1+1, c1, r2+1, c2));
            maxNext = Math.max(maxNext, dfs(r1+1, c1, r2, c2+1));
            maxNext = Math.max(maxNext, dfs(r1, c1+1, r2+1, c2));
            maxNext = Math.max(maxNext, dfs(r1, c1+1, r2, c2+1));
            
            dp[r1][c1][r2][c2] = cherries + maxNext;
            return dp[r1][c1][r2][c2];
        }
        console.log(Math.max(0, dfs(0,0,0,0)));
        rl.close();
    }
});
