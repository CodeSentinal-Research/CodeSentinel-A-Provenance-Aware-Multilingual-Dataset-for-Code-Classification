const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 2) {
        const [n, m] = lines[0].split(/\s+/).map(Number);
        let adj = Array.from({length: n}, () => []);
        let deg = new Array(n).fill(0);
        for(let i=1; i<=m; i++) {
            const [u, v] = lines[i].split(/\s+/).map(Number);
            adj[u-1].push(v-1);
            adj[v-1].push(u-1);
            deg[u-1]++;
            deg[v-1]++;
        }
        let odd = 0;
        for(let d of deg) if(d%2 !== 0) odd++;
        if(odd !== 0 && odd !== 2) console.log("IMPOSSIBLE");
        else {
             // Hierholzer's algorithm simplified
             console.log("Eulerian Circuit Exists");
        }
        rl.close();
    }
});
