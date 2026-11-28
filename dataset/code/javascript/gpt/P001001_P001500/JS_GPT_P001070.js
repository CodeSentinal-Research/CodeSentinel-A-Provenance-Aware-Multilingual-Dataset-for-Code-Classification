// P001070 - Check Whether a Graph is Bipartite
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    const m = parseInt(input[1], 10);
    let ptr = 2;
    const adj = Array.from({ length: n }, () => []);
    for (let i = 0; i < m; i++) {
        const u = parseInt(input[ptr++], 10);
        const v = parseInt(input[ptr++], 10);
        adj[u].push(v);
        adj[v].push(u);
    }
    const color = new Array(n).fill(-1);
    for (let i = 0; i < n; i++) {
        if (color[i] === -1) {
            const queue = [i];
            color[i] = 0;
            while (queue.length > 0) {
                const u = queue.shift();
                for (const v of adj[u]) {
                    if (color[v] === -1) {
                        color[v] = 1 - color[u];
                        queue.push(v);
                    } else if (color[v] === color[u]) {
                        console.log("NO");
                        return;
                    }
                }
            }
        }
    }
    console.log("YES");
}

main();
