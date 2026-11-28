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
        let disc = new Array(n).fill(-1);
        let low = new Array(n).fill(-1);
        let timer = 0;
        let ap = new Set();
        function dfs(u, parent) {
            disc[u] = low[u] = timer++;
            let children = 0;
            for(let v of adj[u]) {
                if(disc[v] === -1) {
                    children++;
                    dfs(v, u);
                    low[u] = Math.min(low[u], low[v]);
                    if(parent === -1 && children > 1) ap.add(u);
                    if(parent !== -1 && low[v] >= disc[u]) ap.add(u);
                } else if(v !== parent) {
                    low[u] = Math.min(low[u], disc[v]);
                }
            }
        }
        for(let i=0; i<n; i++) if(disc[i] === -1) dfs(i, -1);
        let res = Array.from(ap).sort((a,b) => a-b).map(x => x+1);
        console.log(res.length > 0 ? res.join(" ") : "NONE");
        rl.close();
    }
});
