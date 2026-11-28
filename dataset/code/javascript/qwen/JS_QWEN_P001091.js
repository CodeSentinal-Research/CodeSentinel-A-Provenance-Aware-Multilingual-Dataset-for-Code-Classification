const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 3) {
        const [n, q] = lines[0].split(/\s+/).map(Number);
        let parent = new Array(n).fill(-1);
        let depth = new Array(n).fill(0);
        let adj = Array.from({length: n}, () => []);
        for(let i=1; i<n; i++) {
            const [u, v] = lines[i].split(/\s+/).map(Number);
            adj[u-1].push(v-1);
            adj[v-1].push(u-1);
        }
        // Binary Lifting
        let LOG = Math.ceil(Math.log2(n));
        let up = Array.from({length: n}, () => new Array(LOG).fill(-1));
        
        function dfs(u, p) {
            up[u][0] = p;
            for(let i=1; i<LOG; i++) {
                if(up[u][i-1] !== -1) up[u][i] = up[up[u][i-1]][i-1];
            }
            for(let v of adj[u]) {
                if(v !== p) {
                    depth[v] = depth[u] + 1;
                    dfs(v, u);
                }
            }
        }
        dfs(0, -1);
        
        function lca(a, b) {
            if(depth[a] < depth[b]) [a, b] = [b, a];
            let diff = depth[a] - depth[b];
            for(let i=0; i<LOG; i++) {
                if(diff & (1<<i)) a = up[a][i];
            }
            if(a === b) return a;
            for(let i=LOG-1; i>=0; i--) {
                if(up[a][i] !== up[b][i]) {
                    a = up[a][i];
                    b = up[b][i];
                }
            }
            return up[a][0];
        }
        
        let res = [];
        for(let i=n; i<n+q; i++) {
            const [u, v] = lines[i].split(/\s+/).map(Number);
            res.push(lca(u-1, v-1)+1);
        }
        console.log(res.join("\n"));
        rl.close();
    }
});
