const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === parseInt(lines[0]) + 1) {
        const n = parseInt(lines[0]);
        let maze = [];
        for(let i=1; i<=n; i++) maze.push(lines[i].split(/\s+/).map(Number));
        
        let res = [];
        function solve(r, c, path) {
            if(r===n-1 && c===n-1) {
                res.push(path);
                return;
            }
            maze[r][c] = 0;
            if(r+1<n && maze[r+1][c]===1) solve(r+1, c, path+"D");
            if(c+1<n && maze[r][c+1]===1) solve(r, c+1, path+"R");
            if(r-1>=0 && maze[r-1][c]===1) solve(r-1, c, path+"U");
            if(c-1>=0 && maze[r][c-1]===1) solve(r, c-1, path+"L");
            maze[r][c] = 1;
        }
        
        if(maze[0][0]===1) solve(0, 0, "");
        console.log(res.join("\n"));
        rl.close();
    }
});
