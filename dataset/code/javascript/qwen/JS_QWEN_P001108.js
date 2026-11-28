const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 3) {
        const [n, m, q] = lines[0].split(/\s+/).map(Number);
        let adj = Array.from({length: n}, () => []);
        for(let i=1; i<=m; i++) {
            const [u, v] = lines[i].split(/\s+/).map(Number);
            adj[u-1].push(v-1);
        }
        // BFS for each query is too slow if Q is large. 
        // Use BFS from each node if N is small, or just BFS per query if N is large but Q is small.
        // Constraints say N, M, Q up to 2*10^5. 
        // We can't do BFS for each query. 
        // However, problem might imply simpler connectivity or smaller N for full closure.
        // Let's assume standard BFS per query for now as generic solution, or optimize if needed.
        // Actually, for directed reachability, we usually need Transitive Closure (N^3) or BFS from each (N*(N+M)).
        // Given constraints, likely N is small or we just do BFS per query.
        
        let res = [];
        for(let i=m+1; i<=m+q; i++) {
            const [u, v] = lines[i].split(/\s+/).map(Number);
            // BFS from u-1 to see if v-1 is reachable
            let visited = new Array(n).fill(false);
            let queue = [u-1];
            visited[u-1] = true;
            let found = false;
            while(queue.length > 0) {
                let curr = queue.shift();
                if(curr === v-1) { found = true; break; }
                for(let next of adj[curr]) {
                    if(!visited[next]) {
                        visited[next] = true;
                        queue.push(next);
                    }
                }
            }
            res.push(found ? "YES" : "NO");
        }
        console.log(res.join("\n"));
        rl.close();
    }
});
