const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 3) {
        const e = parseInt(lines[0]);
        let graph = {};
        for(let i=1; i<=e; i++) {
            const [a, b, val] = lines[i].split(/\s+/);
            const v = parseFloat(val);
            if(!graph[a]) graph[a] = [];
            if(!graph[b]) graph[b] = [];
            graph[a].push([b, v]);
            graph[b].push([a, 1/v]);
        }
        const q = parseInt(lines[e+1]);
        let res = [];
        for(let i=e+2; i<e+2+q; i++) {
            const [src, dest] = lines[i].split(/\s+/);
            if(!graph[src] || !graph[dest]) { res.push(-1.0); continue; }
            if(src === dest) { res.push(1.0); continue; }
            
            let queue = [[src, 1.0]];
            let visited = new Set([src]);
            let found = false;
            while(queue.length > 0) {
                let [curr, prod] = queue.shift();
                if(curr === dest) { res.push(prod); found = true; break; }
                for(let [next, val] of graph[curr]) {
                    if(!visited.has(next)) {
                        visited.add(next);
                        queue.push([next, prod * val]);
                    }
                }
            }
            if(!found) res.push(-1.0);
        }
        console.log(res.map(r => r.toFixed(5)).join("\n"));
        rl.close();
    }
});
