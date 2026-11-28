const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 3) {
        const [n, m] = lines[0].split(/\s+/).map(Number);
        let adj = Array.from({length: n}, () => []);
        for(let i=1; i<=m; i++) {
            const [u, v] = lines[i].split(/\s+/).map(Number);
            adj[u-1].push(v-1);
            adj[v-1].push(u-1);
        }
        const colors = lines[m+1].split(/\s+/).map(Number);
        let valid = true;
        for(let u=0; u<n; u++) {
            for(let v of adj[u]) {
                if(colors[u] === colors[v]) { valid = false; break; }
            }
            if(!valid) break;
        }
        console.log(valid ? "VALID" : "INVALID");
        rl.close();
    }
});
