// P001094 - Maximum Bipartite Matching
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 3) return;
    const uCount = parseInt(input[0], 10);
    const vCount = parseInt(input[1], 10);
    const m = parseInt(input[2], 10);
    let ptr = 3;
    const adj = Array.from({ length: uCount }, () => []);
    for (let i = 0; i < m; i++) {
        const u = parseInt(input[ptr++], 10);
        const v = parseInt(input[ptr++], 10);
        adj[u].push(v);
    }
    const match = new Array(vCount).fill(-1);
    function bpm(u, seen) {
        for (const v of adj[u]) {
            if (!seen[v]) {
                seen[v] = true;
                if (match[v] < 0 || bpm(match[v], seen)) {
                    match[v] = u;
                    return true;
                }
            }
        }
        return false;
    }
    let result = 0;
    for (let u = 0; u < uCount; u++) {
        const seen = new Array(vCount).fill(false);
        if (bpm(u, seen)) result++;
    }
    console.log(result);
}

main();
