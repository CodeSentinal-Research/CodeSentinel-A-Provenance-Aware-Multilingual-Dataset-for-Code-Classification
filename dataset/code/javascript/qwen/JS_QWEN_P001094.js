const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 3) {
        const [l, r, m] = lines[0].split(/\s+/).map(Number);
        let adj = Array.from({length: l}, () => []);
        for(let i=1; i<=m; i++) {
            const [u, v] = lines[i].split(/\s+/).map(Number);
            adj[u-1].push(v-1);
        }
        let matchR = new Array(r).fill(-1);
        function dfs(u, seen) {
            for(let v of adj[u]) {
                if(!seen[v]) {
                    seen[v] = true;
                    if(matchR[v] === -1 || dfs(matchR[v], seen)) {
                        matchR[v] = u;
                        return true;
                    }
                }
            }
            return false;
        }
        let count = 0;
        for(let u=0; u<l; u++) {
            let seen = new Array(r).fill(false);
            if(dfs(u, seen)) count++;
        }
        console.log(count);
        rl.close();
    }
});
