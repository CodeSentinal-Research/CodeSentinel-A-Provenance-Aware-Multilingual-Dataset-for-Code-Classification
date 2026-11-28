const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 2) {
        const n = parseInt(lines[0]);
        let adj = {};
        for(let i=1; i<=n; i++) {
            const [src, dest] = lines[i].split(/\s+/);
            if(!adj[src]) adj[src] = [];
            adj[src].push(dest);
        }
        // Sort destinations lexicographically
        for(let k in adj) adj[k].sort();
        
        let itinerary = [];
        function dfs(u) {
            while(adj[u] && adj[u].length > 0) {
                let v = adj[u].shift();
                dfs(v);
            }
            itinerary.push(u);
        }
        dfs("JFK");
        console.log(itinerary.reverse().join(" "));
        rl.close();
    }
});
