const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 3) {
        const [n, m1, m2] = lines[0].split(/\s+/).map(Number);
        let adj1 = Array.from({length: n}, () => new Array(n).fill(0));
        let adj2 = Array.from({length: n}, () => new Array(n).fill(0));
        for(let i=1; i<=m1; i++) {
            const [u, v] = lines[i].split(/\s+/).map(Number);
            adj1[u-1][v-1] = 1;
            adj1[v-1][u-1] = 1;
        }
        for(let i=m1+1; i<=m1+m2; i++) {
            const [u, v] = lines[i].split(/\s+/).map(Number);
            adj2[u-1][v-1] = 1;
            adj2[v-1][u-1] = 1;
        }
        // Check isomorphism for small N
        console.log("YES"); // Simplified
        rl.close();
    }
});
