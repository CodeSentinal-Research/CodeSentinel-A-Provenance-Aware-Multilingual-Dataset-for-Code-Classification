const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 3) {
        const [n, m, s, t] = lines[0].split(/\s+/).map(Number);
        let adj = Array.from({length: n}, () => []);
        for(let i=1; i<=m; i++) {
            const [u, v] = lines[i].split(/\s+/).map(Number);
            adj[u-1].push(v-1);
        }
        let dp = new Array(n).fill(0);
        dp[s-1] = 1;
        // Topological Sort
        let inDegree = new Array(n).fill(0);
        for(let u=0; u<n; u++) for(let v of adj[u]) inDegree[v]++;
        let queue = [];
        for(let i=0; i<n; i++) if(inDegree[i] === 0) queue.push(i);
        let order = [];
        while(queue.length > 0) {
            let u = queue.shift();
            order.push(u);
            for(let v of adj[u]) {
                inDegree[v]--;
                if(inDegree[v] === 0) queue.push(v);
            }
        }
        for(let u of order) {
            for(let v of adj[u]) {
                dp[v] += dp[u];
            }
        }
        console.log(dp[t-1]);
        rl.close();
    }
});
