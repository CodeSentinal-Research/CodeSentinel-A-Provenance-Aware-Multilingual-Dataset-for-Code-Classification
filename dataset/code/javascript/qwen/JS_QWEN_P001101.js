const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === parseInt(lines[0]) + 2) {
        const n = parseInt(lines[0]);
        let edges = [];
        for(let i=1; i<=n; i++) {
            const [u, v] = lines[i].split(/\s+/).map(Number);
            edges.push([u-1, v-1]);
        }
        // Find redundant edge using Union-Find
        let parent = new Array(n).fill(0).map((_, i) => i);
        function find(u) {
            if(parent[u] !== u) parent[u] = find(parent[u]);
            return parent[u];
        }
        function union(u, v) {
            let pu = find(u), pv = find(v);
            if(pu === pv) return false;
            parent[pu] = pv;
            return true;
        }
        for(let [u, v] of edges) {
            if(!union(u, v)) {
                console.log(`${u+1} ${v+1}`);
                rl.close();
                return;
            }
        }
        rl.close();
    }
});
