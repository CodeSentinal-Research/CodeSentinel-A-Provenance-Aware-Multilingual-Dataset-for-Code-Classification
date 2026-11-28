const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 2) {
        const [n, m] = lines[0].split(/\s+/).map(Number);
        let parent = new Array(n).fill(0).map((_, i) => i);
        function find(u) {
            if(parent[u] !== u) parent[u] = find(parent[u]);
            return parent[u];
        }
        function union(u, v) {
            let pu = find(u), pv = find(v);
            if(pu !== pv) parent[pu] = pv;
            return true;
        }
        let cycle = false;
        for(let i=1; i<=m; i++) {
            const [u, v] = lines[i].split(/\s+/).map(Number);
            if(find(u-1) === find(v-1)) cycle = true;
            else union(u-1, v-1);
        }
        console.log(cycle ? "YES" : "NO");
        rl.close();
    }
});
