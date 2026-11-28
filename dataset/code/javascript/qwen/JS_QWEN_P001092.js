const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 3) {
        const [n, q] = lines[0].split(/\s+/).map(Number);
        let adj = Array.from({length: n}, () => []);
        for(let i=1; i<n; i++) {
            const [u, v] = lines[i].split(/\s+/).map(Number);
            adj[u-1].push(v-1);
            adj[v-1].push(u-1);
        }
        let LOG = Math.ceil(Math.log2(n));
        let up = Array.from({length: n}, () => new Array(LOG).fill(-1));
        let depth = new Array(n).fill(0);
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
        
        let res = [];
        for(let i=n; i<n+q; i++) {
            const [node, k] = lines[i].split(/\s+/).map(Number);
            let u = node - 1;
            for(let i=0; i<LOG; i++) {
                if(k & (1<<i)) u = up[u][i];
                if(u === -1) break;
            }
            res.push(u === -1 ? -1 : u+1);
        }
        console.log(res.join("\n"));
        rl.close();
    }
});
