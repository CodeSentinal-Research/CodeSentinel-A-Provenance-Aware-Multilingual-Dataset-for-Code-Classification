// P001344 - All Paths from Source to Target
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
    }
    const paths = [];
    function dfs(u, path) {
        if (u === n - 1) {
            paths.push([...path]);
            return;
        }
        for (const v of adj[u]) {
            path.push(v);
            dfs(v, path);
            path.pop();
        }
    }
    dfs(0, [0]);
    for (const p of paths) console.log(p.join(" "));
}

main();
