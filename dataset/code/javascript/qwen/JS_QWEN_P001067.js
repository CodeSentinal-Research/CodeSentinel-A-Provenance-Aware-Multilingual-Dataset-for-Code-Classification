const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 3) {
        const [n, m, s] = lines[0].split(/\s+/).map(Number);
        let adj = Array.from({length: n}, () => []);
        for(let i=1; i<=m; i++) {
            const [u, v] = lines[i].split(/\s+/).map(Number);
            adj[u-1].push(v-1);
            adj[v-1].push(u-1);
        }
        let visited = new Array(n).fill(false);
        let queue = [s-1];
        visited[s-1] = true;
        let count = 0;
        while(queue.length > 0) {
            let u = queue.shift();
            count++;
            for(let v of adj[u]) {
                if(!visited[v]) {
                    visited[v] = true;
                    queue.push(v);
                }
            }
        }
        console.log(count);
        rl.close();
    }
});
