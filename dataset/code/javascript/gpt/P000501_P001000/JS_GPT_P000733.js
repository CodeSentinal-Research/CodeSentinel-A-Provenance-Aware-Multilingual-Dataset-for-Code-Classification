// M-Coloring Problem
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function can_color(v, adj, m) {
    let colors = ([0] * v);
    function is_safe(node, c) {
        for (const neighbor of adj[node]) {
            if (colors[neighbor] === c) {
                return false;
            }
        }
        return true;
    }
    function backtrack(node) {
        if (node === v) {
            return true;
        }
        for (const c of Array.from({length: ((m + 1)) - (1)}, (_, i) => (1) + i)) {
            if (is_safe(node, c)) {
                colors[node] = c;
                if (backtrack((node + 1))) {
                    return true;
                }
                colors[node] = 0;
            }
        }
        return false;
    }
    return backtrack(0);
}
function main() {
    let tokens = _stdin_all.trim().split(/\s+/);
    if (tokens) {
        let v = parseInt(tokens[0], 10);
        let e = parseInt(tokens[1], 10);
        let adj = [...Array.from({length: v}, (_, i) => i)].map(_ => []);
        let idx = 2;
        for (const _ of Array.from({length: e}, (_, i) => i)) {
            let [u, w] = [parseInt(tokens[idx], 10), parseInt(tokens[(idx + 1)], 10)];
            adj[u].push(w);
            adj[w].push(u);
            idx += 2;
        }
        let m = parseInt(tokens[idx], 10);
        console.log((can_color(v, adj, m) ? "true" : "false"));
    }
}
main();
