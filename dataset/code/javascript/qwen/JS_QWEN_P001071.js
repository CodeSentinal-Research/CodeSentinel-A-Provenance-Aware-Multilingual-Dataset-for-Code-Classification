const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 2) {
        const [n, m] = lines[0].split(/\s+/).map(Number);
        let adj = Array.from({length: n}, () => []);
        let revAdj = Array.from({length: n}, () => []);
        for(let i=1; i<=m; i++) {
            const [u, v] = lines[i].split(/\s+/).map(Number);
            adj[u-1].push(v-1);
            revAdj[v-1].push(u-1);
        }
        // Kosaraju's or simple DFS from last finished node
        let visited = new Array(n).fill(false);
        let order = [];
        function dfs1(u) {
            visited[u] = true;
            for(let v of adj[u]) if(!visited[v]) dfs1(v);
            order.push(u);
        }
        for(let i=0; i<n; i++) if(!visited[i]) dfs1(i);
        
        let mother = -1;
        let last = order[order.length-1];
        visited.fill(false);
        function dfs2(u) {
            visited[u] = true;
            for(let v of revAdj[u]) if(!visited[v]) dfs2(v);
        }
        dfs2(last);
        if(visited.every(v => v)) mother = last + 1;
        console.log(mother);
        rl.close();
    }
});
