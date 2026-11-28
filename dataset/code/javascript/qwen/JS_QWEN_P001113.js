const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 2) {
        const [r, c] = lines[0].split(/\s+/).map(Number);
        let grid = [];
        for(let i=1; i<=r; i++) grid.push(lines[i].split(/\s+/).map(Number));
        
        let visited = Array.from({length: r}, () => new Array(c).fill(false));
        let count = 0;
        function dfs(i, j) {
            if(i<0 || i>=r || j<0 || j>=c || grid[i][j]===0 || visited[i][j]) return;
            visited[i][j] = true;
            dfs(i+1, j); dfs(i-1, j); dfs(i, j+1); dfs(i, j-1);
        }
        for(let i=0; i<r; i++) {
            for(let j=0; j<c; j++) {
                if(grid[i][j]===1 && !visited[i][j]) {
                    dfs(i, j);
                    count++;
                }
            }
        }
        console.log(count);
        rl.close();
    }
});
