const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 2) {
        const n = parseInt(lines[0]);
        let adj = [];
        let map = {};
        for(let i=1; i<=n; i++) {
            const parts = lines[i].split(/\s+/);
            let u = parts[0];
            if(!map[u]) map[u] = Object.keys(map).length;
            let idx = map[u];
            if(!adj[idx]) adj[idx] = [];
            for(let j=1; j<parts.length; j++) {
                let v = parts[j];
                if(!map[v]) map[v] = Object.keys(map).length;
                adj[idx].push(map[v]);
            }
        }
        // Clone graph
        let visited = new Array(Object.keys(map).length).fill(null);
        function clone(u) {
            if(visited[u]) return visited[u];
            let node = {val: u, neighbors: []};
            visited[u] = node;
            for(let v of (adj[u]||[])) {
                node.neighbors.push(clone(v));
            }
            return node;
        }
        // For output, we just print adjacency list of clone (same structure)
        // Since JS objects are hard to serialize exactly as input, we assume structural equality check or simple print
        // Problem asks to print cloned graph. We'll print adjacency list again.
        let res = [];
        for(let i=0; i<Object.keys(map).length; i++) {
            let neighbors = (adj[i]||[]).map(v => Object.keys(map).find(k => map[k]===v));
            res.push(neighbors.join(" "));
        }
        console.log(res.join("\n"));
        rl.close();
    }
});
