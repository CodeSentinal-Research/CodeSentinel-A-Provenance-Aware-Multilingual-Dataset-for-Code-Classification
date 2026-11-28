// Binary Tree Maximum Width
const fs = require("fs");
function _in(item, container) { if (Array.isArray(container) || typeof container === "string") return container.includes(item); if (container instanceof Set || container instanceof Map) return container.has(item); if (typeof container === "object" && container !== null) return item in container; return false; }
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function main() {
    let tokens = _stdin_all.trim().split(/\s+/);
    if ((!(tokens) || _in(tokens[0], ["null", "#", "N"]))) {
        console.log(0);
        return;
    }
    let tree = [...tokens].map(t => (_in(t, ["null", "#", "N"]) ? null : parseInt(t, 10)));
    let max_w = 0;
    let q = deque([[0, 1]]);
    while (q) {
        let sz = (q.length !== undefined ? q.length : q.size);
        let [first_pos, last_pos] = [q[0][1], q[-(1)][1]];
        max_w = Math.max(max_w, ((last_pos - first_pos) + 1));
        for (const _ of Array.from({length: sz}, (_, i) => i)) {
            let [idx, pos] = q.popleft();
            let [l, r] = [((2 * idx) + 1), ((2 * idx) + 2)];
            if ((l < (tree.length !== undefined ? tree.length : tree.size) && tree[l] !== null)) {
                q.push([l, (2 * pos)]);
            }
            if ((r < (tree.length !== undefined ? tree.length : tree.size) && tree[r] !== null)) {
                q.push([r, ((2 * pos) + 1)]);
            }
        }
    }
    console.log(max_w);
}
main();
