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
        
        // Find nodes not part of any cycle (Safe nodes)
        // Nodes that eventually lead to a terminal node (no outgoing edges) without entering a cycle.
        // Reverse topological sort / BFS from terminals
        
        let outDegree = adj.map(a => a.length);
        let queue = [];
        for(let i=0; i<n; i++) if(outDegree[i] === 0) queue.push(i);
        
        let safe = new Set();
        while(queue.length > 0) {
            let u = queue.shift();
            safe.add(u);
            for(let v of revAdj[u]) {
                outDegree[v]--;
                if(outDegree[v] === 0) queue.push(v);
            }
        }
        console.log(Array.from(safe).sort((a,b)=>a-b).map(x=>x+1).join(" "));
        rl.close();
    }
});
