const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 2) {
        const n = parseInt(lines[0]);
        let adj = [];
        for(let i=1; i<=n; i++) {
            adj.push(lines[i].split(/\s+/).map(Number).map(x=>x-1));
        }
        // Clone directed graph
        let visited = new Array(n).fill(null);
        function clone(u) {
            if(visited[u]) return visited[u];
            let node = {val: u, neighbors: []};
            visited[u] = node;
            for(let v of adj[u]) {
                node.neighbors.push(clone(v));
            }
            return node;
        }
        // Print adjacency list of clone
        let res = [];
        // Reconstruct from visited map which mirrors structure
        for(let i=0; i<n; i++) {
            let neighbors = adj[i].map(v => v+1);
            res.push(neighbors.join(" "));
        }
        console.log(res.join("\n"));
        rl.close();
    }
});
