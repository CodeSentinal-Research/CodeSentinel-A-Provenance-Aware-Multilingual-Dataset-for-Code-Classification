// Snakes and Ladders
const fs = require("fs");
function _in(item, container) { if (Array.isArray(container) || typeof container === "string") return container.includes(item); if (container instanceof Set || container instanceof Map) return container.has(item); if (typeof container === "object" && container !== null) return item in container; return false; }
function _py_range(start, stop, step = 1) { const res = []; if (step > 0) { for (let i = start; i < stop; i += step) res.push(i); } else { for (let i = start; i > stop; i += step) res.push(i); } return res; }
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function main() {
    let tokens = _stdin_all.trim().split(/\s+/);
    if (tokens) {
        let n = parseInt(tokens[0], 10);
        let idx = 1;
        let board = [];
        for (const _ of Array.from({length: n}, (_, i) => i)) {
            board.push(Array.from(tokens.slice(idx, (idx + n)).map(Number)));
            idx += n;
        }
        let arr = ([-(1)] * ((n * n) + 1));
        let cur = 1;
        for (const r of _py_range((n - 1), -(1), -(1))) {
            let row = ((((n - 1) - r) % 2) === 0 ? board[r] : board[r].slice(0));
            for (const val of row) {
                arr[cur] = val;
                cur += 1;
            }
        }
        let q = deque([[1, 0]]);
        let visited = new Set([1]);
        while (q) {
            let [pos, moves] = q.popleft();
            if (pos === (n * n)) {
                console.log(moves);
                return;
            }
            for (const step of Array.from({length: (7) - (1)}, (_, i) => (1) + i)) {
                let nxt = (pos + step);
                if (nxt <= (n * n)) {
                    let dest = (arr[nxt] !== -(1) ? arr[nxt] : nxt);
                    if (!_in(dest, visited)) {
                        visited.add(dest);
                        q.push([dest, (moves + 1)]);
                    }
                }
            }
        }
        console.log(-(1));
    }
}
main();
