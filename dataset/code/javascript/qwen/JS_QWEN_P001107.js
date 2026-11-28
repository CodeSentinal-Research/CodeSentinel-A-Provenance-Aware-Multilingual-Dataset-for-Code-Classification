const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 2) {
        const [n, m] = lines[0].split(/\s+/).map(Number);
        let reach = Array.from({length: n}, () => new Array(n).fill(0));
        for(let i=0; i<n; i++) reach[i][i] = 1;
        for(let i=1; i<=m; i++) {
            const [u, v] = lines[i].split(/\s+/).map(Number);
            reach[u-1][v-1] = 1;
        }
        // Floyd Warshall for transitive closure
        for(let k=0; k<n; k++) {
            for(let i=0; i<n; i++) {
                for(let j=0; j<n; j++) {
                    if(reach[i][k] && reach[k][j]) reach[i][j] = 1;
                }
            }
        }
        reach.forEach(row => console.log(row.join(" ")));
        rl.close();
    }
});
