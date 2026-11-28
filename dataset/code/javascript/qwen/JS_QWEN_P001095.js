const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 3) {
        const [n, m, s, t] = lines[0].split(/\s+/).map(Number);
        let cap = Array.from({length: n}, () => new Array(n).fill(0));
        for(let i=1; i<=m; i++) {
            const [u, v, c] = lines[i].split(/\s+/).map(Number);
            cap[u-1][v-1] += c;
        }
        let flow = 0;
        while(true) {
            let parent = new Array(n).fill(-1);
            let queue = [s-1];
            parent[s-1] = s-1;
            let head = 0;
            while(head < queue.length) {
                let u = queue[head++];
                for(let v=0; v<n; v++) {
                    if(parent[v] === -1 && cap[u][v] > 0) {
                        parent[v] = u;
                        queue.push(v);
                    }
                }
            }
            if(parent[t-1] === -1) break;
            let pathFlow = Infinity;
            let v = t-1;
            while(v !== s-1) {
                let u = parent[v];
                pathFlow = Math.min(pathFlow, cap[u][v]);
                v = u;
            }
            v = t-1;
            while(v !== s-1) {
                let u = parent[v];
                cap[u][v] -= pathFlow;
                cap[v][u] += pathFlow;
                v = u;
            }
            flow += pathFlow;
        }
        console.log(flow);
        rl.close();
    }
});
