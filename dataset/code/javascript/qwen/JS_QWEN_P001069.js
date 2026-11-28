const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 3) {
        const [n, m, s] = lines[0].split(/\s+/).map(Number);
        let adj = Array.from({length: n}, () => []);
        for(let i=1; i<=m; i++) {
            const [u, v, w] = lines[i].split(/\s+/).map(Number);
            adj[u-1].push([v-1, w]);
        }
        // Topological Sort + DP
        let inDegree = new Array(n).fill(0);
        for(let i=0; i<n; i++) {
            for(let [v, w] of adj[i]) inDegree[v]++;
        }
        let queue = [];
        for(let i=0; i<n; i++) if(inDegree[i] === 0) queue.push(i);
        let dist = new Array(n).fill(Infinity);
        dist[s-1] = 0;
        let order = [];
        while(queue.length > 0) {
            let u = queue.shift();
            order.push(u);
            for(let [v, w] of adj[u]) {
                inDegree[v]--;
                if(inDegree[v] === 0) queue.push(v);
            }
        }
        for(let u of order) {
            if(dist[u] !== Infinity) {
                for(let [v, w] of adj[u]) {
                    if(dist[u] + w < dist[v]) dist[v] = dist[u] + w;
                }
            }
        }
        console.log(dist.map(d => d === Infinity ? -1 : d).join(" "));
        rl.close();
    }
});
