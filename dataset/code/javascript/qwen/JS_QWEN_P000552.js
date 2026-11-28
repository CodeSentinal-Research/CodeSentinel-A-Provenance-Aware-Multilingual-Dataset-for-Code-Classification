const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === parseInt(lines[0].split(' ')[0])+1) {
        const [m, n] = lines[0].split(/\s+/).map(Number);
        let grid = [];
        for(let i=1; i<=m; i++) grid.push(lines[i].split(/\s+/).map(Number));
        let q = [];
        for(let i=0; i<m; i++) {
            for(let j=0; j<n; j++) {
                if(grid[i][j]===0) q.push([i,j]);
                else grid[i][j] = 2147483647;
            }
        }
        let dirs = [[0,1],[0,-1],[1,0],[-1,0]];
        while(q.length) {
            let [r,c] = q.shift();
            for(let [dr,dc] of dirs) {
                let nr=r+dr, nc=c+dc;
                if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc] > grid[r][c]+1) {
                    grid[nr][nc] = grid[r][c]+1;
                    q.push([nr,nc]);
                }
            }
        }
        grid.forEach(row => console.log(row.join(" ")));
        rl.close();
    }
});
