// Binary Tree Vertical Order Traversal
const fs = require("fs");
function _in(item, container) { if (Array.isArray(container) || typeof container === "string") return container.includes(item); if (container instanceof Set || container instanceof Map) return container.has(item); if (typeof container === "object" && container !== null) return item in container; return false; }
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function main() {
    let tokens = _stdin_all.trim().split(/\s+/);
    if ((!(tokens) || _in(tokens[0], ["null", "#", "N"]))) {
        return;
    }
    let tree = [...tokens].map(t => (_in(t, ["null", "#", "N"]) ? null : parseInt(t, 10)));
    let cols = defaultdict(list);
    let q = deque([[0, 0]]);
    while (q) {
        let [idx, col] = q.popleft();
        if ((idx >= (tree.length !== undefined ? tree.length : tree.size) || tree[idx] === null)) {
            continue;
        }
        cols[col].push(tree[idx]);
        let [l, r] = [((2 * idx) + 1), ((2 * idx) + 2)];
        if (l < (tree.length !== undefined ? tree.length : tree.size)) {
            q.push([l, (col - 1)]);
        }
        if (r < (tree.length !== undefined ? tree.length : tree.size)) {
            q.push([r, (col + 1)]);
        }
    }
    for (const c of [...cols].sort((a, b) => a < b ? -1 : a > b ? 1 : 0)) {
        console.log(...cols[c]);
    }
}
main();
