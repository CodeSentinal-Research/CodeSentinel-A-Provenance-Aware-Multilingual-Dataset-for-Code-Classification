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
        let bridges = [];
        function dfs(u, parent) {
            disc[u] = low[u] = timer++;
            for(let v of adj[u]) {
                if(v === parent) continue;
                if(disc[v] === -1) {
                    dfs(v, u);
                    low[u] = Math.min(low[u], low[v]);
                    if(low[v] > disc[u]) bridges.push([Math.min(u+1, v+1), Math.max(u+1, v+1)]);
                } else {
                    low[u] = Math.min(low[u], disc[v]);
                }
            }
        }
        for(let i=0; i<n; i++) if(disc[i] === -1) dfs(i, -1);
        if(bridges.length === 0) console.log("NONE");
        else console.log(bridges.sort((a,b)=>a[0]-b[0]||a[1]-b[1]).map(b=>b.join(" ")).join("\n"));
        rl.close();
    }
});
