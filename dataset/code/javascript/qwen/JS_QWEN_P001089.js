const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 2) {
        const n = parseInt(lines[0]);
        let adj = Array.from({length: n}, () => []);
        for(let i=1; i<n; i++) {
            const [u, v] = lines[i].split(/\s+/).map(Number);
            adj[u-1].push(v-1);
            adj[v-1].push(u-1);
        }
        let deg = new Array(n).fill(0);
        for(let i=0; i<n; i++) deg[i] = adj[i].length;
        let leaves = [];
        for(let i=0; i<n; i++) if(deg[i] === 1) leaves.push(i);
        let removed = 0;
        while(n - removed > 2) {
            let newLeaves = [];
            for(let u of leaves) {
                removed++;
                for(let v of adj[u]) {
                    deg[v]--;
                    if(deg[v] === 1) newLeaves.push(v);
                }
            }
            leaves = newLeaves;
        }
        console.log(leaves.map(x => x+1).sort((a,b)=>a-b).join(" "));
        rl.close();
    }
});
