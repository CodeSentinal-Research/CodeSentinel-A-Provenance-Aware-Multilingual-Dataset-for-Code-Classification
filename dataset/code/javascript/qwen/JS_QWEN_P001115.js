const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 2) {
        const n = parseInt(lines[0]);
        let grid = [];
        for(let i=1; i<=n; i++) grid.push(lines[i].split(/\s+/).map(Number));
        
        if(grid[0][0]===1 || grid[n-1][n-1]===1) { console.log(-1); rl.close(); return; }
        
        let queue = [[0, 0, 1]];
        let visited = Array.from({length: n}, () => new Array(n).fill(false));
        visited[0][0] = true;
        let dirs = [[0,1],[0,-1],[1,0],[-1,0],[1,1],[1,-1],[-1,1],[-1,-1]];
        
        while(queue.length > 0) {
            let [i, j, d] = queue.shift();
            if(i===n-1 && j===n-1) { console.log(d); rl.close(); return; }
            for(let [di, dj] of dirs) {
                let ni = i+di, nj = j+dj;
                if(ni>=0 && ni<n && nj>=0 && nj<n && !visited[ni][nj] && grid[ni][nj]===0) {
                    visited[ni][nj] = true;
                    queue.push([ni, nj, d+1]);
                }
            }
        }
        console.log(-1);
        rl.close();
    }
});
