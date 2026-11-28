// P001096 - Minimum Cut
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 4) return;
    const n = parseInt(input[0], 10);
    const m = parseInt(input[1], 10);
    const s = parseInt(input[2], 10);
    const t = parseInt(input[3], 10);
    let ptr = 4;
    const capacity = Array.from({ length: n }, () => new Array(n).fill(0));
    const origCapacity = Array.from({ length: n }, () => new Array(n).fill(0));
    const adj = Array.from({ length: n }, () => []);
    for (let i = 0; i < m; i++) {
        const u = parseInt(input[ptr++], 10);
        const v = parseInt(input[ptr++], 10);
        const c = parseInt(input[ptr++], 10);
        capacity[u][v] += c;
        origCapacity[u][v] += c;
        adj[u].push(v);
        adj[v].push(u);
    }
    while (true) {
        const parent = new Array(n).fill(-1);
        const queue = [s];
        parent[s] = s;
        while (queue.length > 0 && parent[t] === -1) {
            const u = queue.shift();
            for (const v of adj[u]) {
                if (parent[v] === -1 && capacity[u][v] > 0) {
                    parent[v] = u;
                    queue.push(v);
                }
            }
        }
        if (parent[t] === -1) break;
        let push = Infinity;
        let curr = t;
        while (curr !== s) {
            const prev = parent[curr];
            push = Math.min(push, capacity[prev][curr]);
            curr = prev;
        }
        curr = t;
        while (curr !== s) {
            const prev = parent[curr];
            capacity[prev][curr] -= push;
            capacity[curr][prev] += push;
            curr = prev;
        }
    }
    const visited = new Array(n).fill(false);
    const q = [s];
    visited[s] = true;
    while (q.length > 0) {
        const u = q.shift();
        for (const v of adj[u]) {
            if (!visited[v] && capacity[u][v] > 0) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
    let minCutWeight = 0;
    for (let u = 0; u < n; u++) {
        for (let v = 0; v < n; v++) {
            if (visited[u] && !visited[v] && origCapacity[u][v] > 0) {
                minCutWeight += origCapacity[u][v];
            }
        }
    }
    console.log(minCutWeight);
}

main();
