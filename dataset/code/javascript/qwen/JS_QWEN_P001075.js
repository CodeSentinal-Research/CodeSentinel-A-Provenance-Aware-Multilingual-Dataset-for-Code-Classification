const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 3) {
        const [n, m, s] = lines[0].split(/\s+/).map(Number);
        let edges = [];
        for(let i=1; i<=m; i++) {
            const [u, v, w] = lines[i].split(/\s+/).map(Number);
            edges.push([u-1, v-1, w]);
        }
        let dist = new Array(n).fill(Infinity);
        dist[s-1] = 0;
        for(let i=0; i<n-1; i++) {
            for(let [u, v, w] of edges) {
                if(dist[u] !== Infinity && dist[u] + w < dist[v]) dist[v] = dist[u] + w;
            }
        }
        let negativeCycle = false;
        for(let [u, v, w] of edges) {
            if(dist[u] !== Infinity && dist[u] + w < dist[v]) negativeCycle = true;
        }
        console.log(negativeCycle ? "NEGATIVE CYCLE" : dist.map(d => d === Infinity ? -1 : d).join(" "));
        rl.close();
    }
});
