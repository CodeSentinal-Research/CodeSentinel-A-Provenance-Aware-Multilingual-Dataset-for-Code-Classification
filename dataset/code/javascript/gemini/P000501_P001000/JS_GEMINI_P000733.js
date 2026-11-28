const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 2 && tokens[0] !== '') {
        const v = parseInt(tokens[0], 10), e = parseInt(tokens[1], 10);
        const adj = Array.from({length: v}, () => []);
        let idx = 2;
        for (let i = 0; i < e; i++) {
            const u = parseInt(tokens[idx], 10), w = parseInt(tokens[idx+1], 10);
            adj[u].push(w); adj[w].push(u);
            idx += 2;
        }
        const m = parseInt(tokens[idx], 10);
        const colors = new Array(v).fill(0);
        function isSafe(node, c) {
            for (const neighbor of adj[node]) {
                if (colors[neighbor] === c) return false;
            }
            return true;
        }
        function backtrack(node) {
            if (node === v) return true;
            for (let c = 1; c <= m; c++) {
                if (isSafe(node, c)) {
                    colors[node] = c;
                    if (backtrack(node + 1)) return true;
                    colors[node] = 0;
                }
            }
            return false;
        }
        console.log(backtrack(0) ? "true" : "false");
    }
}
main();