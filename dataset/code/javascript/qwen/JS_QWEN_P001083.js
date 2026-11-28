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
        // Backtracking for Hamiltonian Path
        let visited = new Array(n).fill(false);
        let path = [];
        function dfs(u) {
            if(path.length === n) return true;
            for(let v of adj[u]) {
                if(!visited[v]) {
                    visited[v] = true;
                    path.push(v);
                    if(dfs(v)) return true;
                    path.pop();
                    visited[v] = false;
                }
            }
            return false;
        }
        let found = false;
        for(let i=0; i<n; i++) {
            visited[i] = true;
            path.push(i);
            if(dfs(i)) { found = true; break; }
            path.pop();
            visited[i] = false;
        }
        console.log(found ? "YES" : "NO");
        rl.close();
    }
});
