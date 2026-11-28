const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 2) {
        const [n, m, s, d, k] = lines[0].split(/\s+/).map(Number);
        let adj = Array.from({length: n}, () => []);
        for(let i=1; i<=m; i++) {
            const [u, v, w] = lines[i].split(/\s+/).map(Number);
            adj[u-1].push([v-1, w]);
            adj[v-1].push([u-1, w]);
        }
        
        // Dijkstra with stops constraint
        // dist[node][stops] = min cost
        let dist = Array.from({length: n}, () => new Array(k+2).fill(Infinity));
        let pq = [[0, s-1, 0]]; // cost, node, stops
        dist[s-1][0] = 0;
        
        while(pq.length > 0) {
            pq.sort((a,b) => a[0]-b[0]);
            let [cost, u, stops] = pq.shift();
            if(u === d-1) { console.log(cost); rl.close(); return; }
            if(stops > k+1) continue;
            
            for(let [v, w] of adj[u]) {
                if(dist[v][stops+1] > cost + w) {
                    dist[v][stops+1] = cost + w;
                    pq.push([cost+w, v, stops+1]);
                }
            }
        }
        console.log(-1);
        rl.close();
    }
});
