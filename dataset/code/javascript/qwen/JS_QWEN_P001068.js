const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 2) {
        const [n, m] = lines[0].split(/\s+/).map(Number);
        let inDegree = new Array(n).fill(0);
        let adj = Array.from({length: n}, () => []);
        for(let i=1; i<=m; i++) {
            const [u, v] = lines[i].split(/\s+/).map(Number);
            adj[u-1].push(v-1);
            inDegree[v-1]++;
        }
        let queue = [];
        for(let i=0; i<n; i++) if(inDegree[i] === 0) queue.push(i);
        let res = [];
        while(queue.length > 0) {
            let u = queue.shift();
            res.push(u+1);
            for(let v of adj[u]) {
                inDegree[v]--;
                if(inDegree[v] === 0) queue.push(v);
            }
        }
        console.log(res.length === n ? res.join(" ") : "IMPOSSIBLE");
        rl.close();
    }
});
