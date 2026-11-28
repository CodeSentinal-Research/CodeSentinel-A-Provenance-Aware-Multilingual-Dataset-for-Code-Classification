const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 2) {
        const n = parseInt(lines[0]);
        let isConnected = [];
        for(let i=1; i<=n; i++) isConnected.push(lines[i].split(/\s+/).map(Number));
        
        let visited = new Array(n).fill(false);
        let count = 0;
        function dfs(u) {
            visited[u] = true;
            for(let v=0; v<n; v++) {
                if(isConnected[u][v]===1 && !visited[v]) dfs(v);
            }
        }
        for(let i=0; i<n; i++) {
            if(!visited[i]) {
                dfs(i);
                count++;
            }
        }
        console.log(count);
        rl.close();
    }
});
