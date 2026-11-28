const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 2) {
        const [n, m] = lines[0].split(/\s+/).map(Number);
        let dist = Array.from({length: n}, () => Array(n).fill(Infinity));
        for(let i=0; i<n; i++) dist[i][i] = 0;
        for(let i=1; i<=m; i++) {
            const [u, v, w] = lines[i].split(/\s+/).map(Number);
            dist[u-1][v-1] = Math.min(dist[u-1][v-1], w);
            dist[v-1][u-1] = Math.min(dist[v-1][u-1], w);
        }
        for(let k=0; k<n; k++) {
            for(let i=0; i<n; i++) {
                for(let j=0; j<n; j++) {
                    if(dist[i][k] !== Infinity && dist[k][j] !== Infinity) {
                        dist[i][j] = Math.min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
        for(let i=0; i<n; i++) console.log(dist[i].map(d => d === Infinity ? -1 : d).join(" "));
        rl.close();
    }
});
