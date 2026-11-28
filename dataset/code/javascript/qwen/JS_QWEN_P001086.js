const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 3) {
        const [n, m, k] = lines[0].split(/\s+/).map(Number);
        let adj = Array.from({length: n}, () => []);
        for(let i=1; i<=m; i++) {
            const [u, v] = lines[i].split(/\s+/).map(Number);
            adj[u-1].push(v-1);
            adj[v-1].push(u-1);
        }
        const sources = lines[m+1].split(/\s+/).map(Number);
        let dist = new Array(n).fill(-1);
        let queue = [];
        for(let s of sources) {
            dist[s-1] = 0;
            queue.push(s-1);
        }
        let head = 0;
        while(head < queue.length) {
            let u = queue[head++];
            for(let v of adj[u]) {
                if(dist[v] === -1) {
                    dist[v] = dist[u] + 1;
                    queue.push(v);
                }
            }
        }
        console.log(dist.map(d => d === -1 ? -1 : d).join(" "));
        rl.close();
    }
});
