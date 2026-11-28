const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 2) {
        const [n, q] = lines[0].split(/\s+/).map(Number);
        let parent = new Array(n).fill(0).map((_, i) => i);
        function find(u) {
            if(parent[u] !== u) parent[u] = find(parent[u]);
            return parent[u];
        }
        function union(u, v) {
            let pu = find(u), pv = find(v);
            if(pu !== pv) parent[pu] = pv;
        }
        let res = [];
        for(let i=1; i<=q; i++) {
            const parts = lines[i].split(' ');
            if(parts[0] === 'ADD') {
                const u = parseInt(parts[1])-1, v = parseInt(parts[2])-1;
                union(u, v);
            } else {
                const u = parseInt(parts[1])-1, v = parseInt(parts[2])-1;
                res.push(find(u) === find(v) ? "YES" : "NO");
            }
        }
        console.log(res.join("\n"));
        rl.close();
    }
});
