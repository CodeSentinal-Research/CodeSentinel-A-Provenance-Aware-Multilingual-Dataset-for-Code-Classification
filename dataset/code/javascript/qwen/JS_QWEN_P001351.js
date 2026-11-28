const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === parseInt(lines[0]) + 1) {
        const n = parseInt(lines[0]);
        let grid = [];
        for(let i=1; i<=n; i++) grid.push(lines[i].split(/\s+/).map(Number));
        
        let res = [];
        function solve(r, c, path, visited) {
            if(r===n-1 && c===n-1) { res.push(path); return; }
            visited[r][c] = true;
            if(r+1<n && grid[r+1][c]===1 && !visited[r+1][c]) solve(r+1, c, path+"D", visited);
            if(c+1<n && grid[r][c+1]===1 && !visited[r][c+1]) solve(r, c+1, path+"R", visited);
            if(r-1>=0 && grid[r-1][c]===1 && !visited[r-1][c]) solve(r-1, c, path+"U", visited);
            if(c-1>=0 && grid[r][c-1]===1 && !visited[r][c-1]) solve(r, c-1, path+"L", visited);
            visited[r][c] = false;
        }
        
        let visited = Array.from({length: n}, ()=>Array(n).fill(false));
        if(grid[0][0]===1) solve(0, 0, "", visited);
        console.log(res.join("\n"));
        rl.close();
    }
});
