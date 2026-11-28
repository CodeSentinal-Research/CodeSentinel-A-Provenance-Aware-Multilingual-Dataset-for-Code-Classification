const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 2) {
        const n = parseInt(lines[0]);
        let grid = [];
        for(let i=1; i<=n; i++) grid.push(lines[i]);
        
        // Expand grid to 3n x 3n to handle slashes as barriers
        let size = 3*n;
        let expanded = Array.from({length: size}, () => new Array(size).fill(0));
        
        for(let i=0; i<n; i++) {
            for(let j=0; j<n; j++) {
                if(grid[i][j] === '/') {
                    expanded[3*i][3*j+2] = 1;
                    expanded[3*i+1][3*j+1] = 1;
                    expanded[3*i+2][3*j] = 1;
                } else if(grid[i][j] === '\\') {
                    expanded[3*i][3*j] = 1;
                    expanded[3*i+1][3*j+1] = 1;
                    expanded[3*i+2][3*j+2] = 1;
                }
            }
        }
        
        let visited = Array.from({length: size}, () => new Array(size).fill(false));
        let count = 0;
        function dfs(i, j) {
            if(i<0 || i>=size || j<0 || j>=size || expanded[i][j]===1 || visited[i][j]) return;
            visited[i][j] = true;
            dfs(i+1, j); dfs(i-1, j); dfs(i, j+1); dfs(i, j-1);
        }
        
        for(let i=0; i<size; i++) {
            for(let j=0; j<size; j++) {
                if(expanded[i][j]===0 && !visited[i][j]) {
                    dfs(i, j);
                    count++;
                }
            }
        }
        console.log(count);
        rl.close();
    }
});
