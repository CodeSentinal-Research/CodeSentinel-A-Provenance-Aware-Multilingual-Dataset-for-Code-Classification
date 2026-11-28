// Minimum Reverse Operations
const fs = require("fs");
function _in(item, container) { if (Array.isArray(container) || typeof container === "string") return container.includes(item); if (container instanceof Set || container instanceof Map) return container.has(item); if (typeof container === "object" && container !== null) return item in container; return false; }
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function main() {
    let tokens = _stdin_all.trim().split(/\s+/);
    if (tokens) {
        let n = parseInt(tokens[0], 10);
        let p = parseInt(tokens[1], 10);
        let b = parseInt(tokens[2], 10);
        let banned = new Set(tokens.slice(3, (3 + b)).map(Number));
        let k = parseInt(tokens[(3 + b)], 10);
        let res = ([-(1)] * n);
        res[p] = 0;
        let unvisited = [new Set(), new Set()];
        for (const i of Array.from({length: n}, (_, i) => i)) {
            if ((i !== p && !_in(i, banned))) {
                unvisited[(i % 2)].add(i);
            }
        }
        let q = deque([p]);
        while (q) {
            let cur = q.popleft();
            let min_idx = Math.max(((cur - k) + 1), ((k - 1) - cur));
            let max_idx = Math.min(((cur + k) - 1), ((((2 * n) - k) - 1) - cur));
            let parity = (min_idx % 2);
            let to_remove = [];
            for (const nxt of unvisited[parity]) {
                if (min_idx <= nxt && nxt <= max_idx) {
                    res[nxt] = (res[cur] + 1);
                    q.push(nxt);
                    to_remove.push(nxt);
                }
            }
            for (const x of to_remove) {
                (idx => idx !== -1 && unvisited[parity].splice(idx, 1))(unvisited[parity].indexOf(x));
            }
        }
        console.log(...res);
    }
}
main();
