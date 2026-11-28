const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 2) {
        const [n, m] = lines[0].split(/\s+/).map(Number);
        let adj = Array.from({length: n}, () => []);
        for(let i=1; i<=m; i++) {
            const [u, v] = lines[i].split(/\s+/).map(Number);
            adj[u-1].push(v-1);
            adj[v-1].push(u-1);
        }
        let color = new Array(n).fill(-1);
        let isBipartite = true;
        for(let i=0; i<n; i++) {
            if(color[i] === -1) {
                let queue = [i];
                color[i] = 0;
                while(queue.length > 0) {
                    let u = queue.shift();
                    for(let v of adj[u]) {
                        if(color[v] === -1) {
                            color[v] = 1 - color[u];
                            queue.push(v);
                        } else if(color[v] === color[u]) {
                            isBipartite = false;
                            break;
                        }
                    }
                    if(!isBipartite) break;
                }
            }
            if(!isBipartite) break;
        }
        console.log(isBipartite ? "YES" : "NO");
        rl.close();
    }
});
