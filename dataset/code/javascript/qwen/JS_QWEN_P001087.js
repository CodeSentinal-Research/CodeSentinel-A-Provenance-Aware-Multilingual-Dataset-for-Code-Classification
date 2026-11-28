const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 2) {
        const [n, m] = lines[0].split(/\s+/).map(Number);
        let adj = Array.from({length: n}, () => []);
        for(let i=1; i<=m; i++) {
            const [u, v] = lines[i].split(/\s+/).map(Number);
            adj[u-1].push(v-1);
            adj[v-1].push(u-1);
        }
        let visited = new Array(n).fill(false);
        let components = 0;
        function dfs(u) {
            visited[u] = true;
            for(let v of adj[u]) if(!visited[v]) dfs(v);
        }
        for(let i=0; i<n; i++) {
            if(!visited[i]) {
                dfs(i);
                components++;
            }
        }
        console.log(components === 1 && m === n-1 ? "YES" : "NO");
        rl.close();
    }
});
