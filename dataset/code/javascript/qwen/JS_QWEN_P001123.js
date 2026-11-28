const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 2) {
        const [n, m, t] = lines[0].split(/\s+/).map(Number);
        let dist = Array.from({length: n}, () => new Array(n).fill(Infinity));
        for(let i=0; i<n; i++) dist[i][i] = 0;
        
        for(let i=1; i<=m; i++) {
            const [u, v, w] = lines[i].split(/\s+/).map(Number);
            dist[u-1][v-1] = Math.min(dist[u-1][v-1], w);
            dist[v-1][u-1] = Math.min(dist[v-1][u-1], w);
        }
        
        // Floyd Warshall
        for(let k=0; k<n; k++) {
            for(let i=0; i<n; i++) {
                for(let j=0; j<n; j++) {
                    dist[i][j] = Math.min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        
        let minNeighbors = Infinity, city = -1;
        for(let i=0; i<n; i++) {
            let count = 0;
            for(let j=0; j<n; j++) {
                if(i!==j && dist[i][j] <= t) count++;
            }
            if(count < minNeighbors || (count === minNeighbors && i > city)) {
                minNeighbors = count;
                city = i;
            }
        }
        console.log(city+1);
        rl.close();
    }
});
