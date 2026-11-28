const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 2) {
        const [n, e, m] = lines[0].split(/\s+/).map(Number);
        let adj = Array.from({length: n}, () => []);
        for(let i=1; i<=e; i++) {
            const [u, v] = lines[i].split(/\s+/).map(Number);
            adj[u-1].push(v-1);
            adj[v-1].push(u-1);
        }
        // Backtracking for M-coloring
        let color = new Array(n).fill(0);
        function isSafe(u, c) {
            for(let v of adj[u]) if(color[v] === c) return false;
            return true;
        }
        function solve(u) {
            if(u === n) return true;
            for(let c=1; c<=m; c++) {
                if(isSafe(u, c)) {
                    color[u] = c;
                    if(solve(u+1)) return true;
                    color[u] = 0;
                }
            }
            return false;
        }
        console.log(solve(0) ? "YES" : "NO");
        rl.close();
    }
});
