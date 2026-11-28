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
            adj[v-1].push([u-1, w]);
        }
        let dist = new Array(n).fill(Infinity);
        dist[s-1] = 0;
        let visited = new Array(n).fill(false);
        
        for(let i=0; i<n; i++) {
            let u = -1;
            for(let j=0; j<n; j++) {
                if(!visited[j] && (u === -1 || dist[j] < dist[u])) u = j;
            }
            if(dist[u] === Infinity) break;
            visited[u] = true;
            for(let [v, w] of adj[u]) {
                if(dist[u] + w < dist[v]) dist[v] = dist[u] + w;
            }
        }
        console.log(dist.map(d => d === Infinity ? -1 : d).join(" "));
        rl.close();
    }
});
