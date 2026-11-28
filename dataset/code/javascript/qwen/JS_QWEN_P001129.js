const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 2) {
        const [n, m] = lines[0].split(/\s+/).map(Number);
        let edges = [];
        for(let i=1; i<=m; i++) {
            const [t, u, v] = lines[i].split(/\s+/).map(Number);
            edges.push([t, u-1, v-1]);
        }
        
        // Process type 3 first, then 1 and 2 separately
        let parent1 = new Array(n).fill(0).map((_, i) => i);
        let parent2 = new Array(n).fill(0).map((_, i) => i);
        let parent3 = new Array(n).fill(0).map((_, i) => i);
        
        function find(p, u) {
            if(p[u] !== u) p[u] = find(p, p[u]);
            return p[u];
        }
        function union(p, u, v) {
            let pu = find(p, u), pv = find(p, v);
            if(pu === pv) return false;
            p[pu] = pv;
            return true;
        }
        
        let removed = 0;
        // Type 3
        for(let [t, u, v] of edges) {
            if(t===3) {
                if(!union(parent3, u, v)) removed++;
                else {
                    union(parent1, u, v);
                    union(parent2, u, v);
                }
            }
        }
        // Type 1
        for(let [t, u, v] of edges) {
            if(t===1) {
                if(!union(parent1, u, v)) removed++;
            }
        }
        // Type 2
        for(let [t, u, v] of edges) {
            if(t===2) {
                if(!union(parent2, u, v)) removed++;
            }
        }
        
        // Check if both Alice and Bob can traverse all
        let root1 = find(parent1, 0);
        let root2 = find(parent2, 0);
        let aliceOk = true, bobOk = true;
        for(let i=1; i<n; i++) {
            if(find(parent1, i) !== root1) aliceOk = false;
            if(find(parent2, i) !== root2) bobOk = false;
        }
        
        console.log((aliceOk && bobOk) ? removed : -1);
        rl.close();
    }
});
