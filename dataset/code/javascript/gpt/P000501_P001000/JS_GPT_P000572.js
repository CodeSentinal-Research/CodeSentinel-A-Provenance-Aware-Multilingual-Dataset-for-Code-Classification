// Binary Tree Level Order Traversal
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
    let tree = [];
    for (const t of tokens) {
        if (_in(t, ["null", "#", "N"])) {
            tree.push(null);
        } else {
            tree.push(parseInt(t, 10));
        }
    }
    let levels = [];
    let q = deque([[0, 0]]);
    let cur_lvl = -(1);
    while (q) {
        let [idx, lvl] = q.popleft();
        if ((idx >= (tree.length !== undefined ? tree.length : tree.size) || tree[idx] === null)) {
            continue;
        }
        if (lvl >= (levels.length !== undefined ? levels.length : levels.size)) {
            levels.push([]);
        }
        levels[lvl].push(tree[idx]);
        let left_idx = ((2 * idx) + 1);
        let right_idx = ((2 * idx) + 2);
        if (left_idx < (tree.length !== undefined ? tree.length : tree.size)) {
            q.push([left_idx, (lvl + 1)]);
        }
        if (right_idx < (tree.length !== undefined ? tree.length : tree.size)) {
            q.push([right_idx, (lvl + 1)]);
        }
    }
    for (const lvl of levels) {
        console.log(...lvl);
    }
}
main();
