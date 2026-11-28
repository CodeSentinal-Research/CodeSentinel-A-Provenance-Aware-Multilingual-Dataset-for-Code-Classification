const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 2) {
        const n = parseInt(lines[0]);
        let adj = Array.from({length: n}, () => []);
        for(let i=1; i<n; i++) {
            const [u, v] = lines[i].split(/\s+/).map(Number);
            adj[u-1].push(v-1);
            adj[v-1].push(u-1);
        }
        function bfs(start) {
            let dist = new Array(n).fill(-1);
            let queue = [start];
            dist[start] = 0;
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
            let maxDist = 0, node = start;
            for(let i=0; i<n; i++) {
                if(dist[i] > maxDist) {
                    maxDist = dist[i];
                    node = i;
                }
            }
            return [node, maxDist];
        }
        let [u, _] = bfs(0);
        let [v, diam] = bfs(u);
        console.log(diam);
        rl.close();
    }
});
