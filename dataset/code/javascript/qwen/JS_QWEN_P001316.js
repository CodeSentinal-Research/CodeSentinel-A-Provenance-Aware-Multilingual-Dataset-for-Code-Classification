const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 2) {
        const [v, e, m] = lines[0].split(/\s+/).map(Number);
        let adj = Array.from({length: v}, ()=>[]);
        for(let i=1; i<=e; i++) {
            const [u, w] = lines[i].split(/\s+/).map(Number);
            adj[u-1].push(w-1);
            adj[w-1].push(u-1);
        }
        
        let colors = new Array(v).fill(0);
        function isSafe(node, color) {
            for(let neighbor of adj[node]) {
                if(colors[neighbor]===color) return false;
            }
            return true;
        }
        
        function solve(node) {
            if(node===v) return true;
            for(let c=1; c<=m; c++) {
                if(isSafe(node, c)) {
                    colors[node] = c;
                    if(solve(node+1)) return true;
                    colors[node] = 0;
                }
            }
            return false;
        }
        
        console.log(solve(0) ? "YES" : "NO");
        rl.close();
    }
});
