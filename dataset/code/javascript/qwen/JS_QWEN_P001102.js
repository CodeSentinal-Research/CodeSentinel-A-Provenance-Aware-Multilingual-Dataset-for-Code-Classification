const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 2) {
        const [n, m] = lines[0].split(/\s+/).map(Number);
        let edges = [];
        for(let i=1; i<=m; i++) {
            const [u, v, w] = lines[i].split(/\s+/).map(Number);
            edges.push([w, u-1, v-1]);
        }
        edges.sort((a,b) => a[0]-b[0]);
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
        let totalWeight = 0, count = 0;
        for(let [w, u, v] of edges) {
            if(union(u, v)) {
                totalWeight += w;
                count++;
                if(count === n-1) break;
            }
        }
        console.log(count === n-1 ? totalWeight : -1);
        rl.close();
    }
});
