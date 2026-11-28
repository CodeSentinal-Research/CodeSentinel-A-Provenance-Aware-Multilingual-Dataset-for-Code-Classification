// P001083 - Hamiltonian Path
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    const m = parseInt(input[1], 10);
    let ptr = 2;
    const adj = Array.from({ length: n }, () => new Array(n).fill(false));
    for (let i = 0; i < m; i++) {
        const u = parseInt(input[ptr++], 10);
        const v = parseInt(input[ptr++], 10);
        adj[u][v] = true;
        adj[v][u] = true;
    }
    const dp = Array.from({ length: 1 << n }, () => new Array(n).fill(false));
    for (let i = 0; i < n; i++) dp[1 << i][i] = true;
    for (let mask = 1; mask < (1 << n); mask++) {
        for (let i = 0; i < n; i++) {
            if (dp[mask][i]) {
                for (let j = 0; j < n; j++) {
                    if (!(mask & (1 << j)) && adj[i][j]) {
                        dp[mask | (1 << j)][j] = true;
                    }
                }
            }
        }
    }
    const fullMask = (1 << n) - 1;
    let found = false;
    for (let i = 0; i < n; i++) {
        if (dp[fullMask][i]) { found = true; break; }
    }
    console.log(found ? "YES" : "NO");
}

main();
