// P001090 - Diameter of a Tree
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    if (n <= 1) {
        console.log(0);
        return;
    }
    let ptr = 1;
    const adj = Array.from({ length: n }, () => []);
    for (let i = 0; i < n - 1; i++) {
        const u = parseInt(input[ptr++], 10);
        const v = parseInt(input[ptr++], 10);
        adj[u].push(v);
        adj[v].push(u);
    }
    function bfs(start) {
        const dist = new Array(n).fill(-1);
        dist[start] = 0;
        const queue = [start];
        let farNode = start, maxDist = 0;
        while (queue.length > 0) {
            const u = queue.shift();
            if (dist[u] > maxDist) {
                maxDist = dist[u];
                farNode = u;
            }
            for (const v of adj[u]) {
                if (dist[v] === -1) {
                    dist[v] = dist[u] + 1;
                    queue.push(v);
                }
            }
        }
        return { farNode, maxDist };
    }
    const nodeA = bfs(0).farNode;
    const diameter = bfs(nodeA).maxDist;
    console.log(diameter);
}

main();
