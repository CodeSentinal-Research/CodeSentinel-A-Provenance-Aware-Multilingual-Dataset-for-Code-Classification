const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 2) {
        const [n, m, s] = lines[0].split(/\s+/).map(Number);
        let adj = Array.from({length: n}, () => []);
        for(let i=1; i<=m; i++) {
            const [u, v, w] = lines[i].split(/\s+/).map(Number);
            adj[u-1].push([v-1, w]);
        }
        
        let dist = new Array(n).fill(Infinity);
        dist[s-1] = 0;
        let pq = [[0, s-1]];
        
        while(pq.length > 0) {
            pq.sort((a,b) => a[0]-b[0]);
            let [d, u] = pq.shift();
            if(d > dist[u]) continue;
            for(let [v, w] of adj[u]) {
                if(dist[v] > d + w) {
                    dist[v] = d + w;
                    pq.push([dist[v], v]);
                }
            }
        }
        
        let maxDist = Math.max(...dist.filter(d => d !== Infinity));
        console.log(maxDist === Infinity ? -1 : maxDist);
        rl.close();
    }
});
