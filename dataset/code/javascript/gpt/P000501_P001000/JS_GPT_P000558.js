// Minimum Moves to Reach Target with Rotations
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
        let idx = 1;
        let grid = [];
        for (const _ of Array.from({length: n}, (_, i) => i)) {
            grid.push(Array.from(tokens.slice(idx, (idx + n)).map(Number)));
            idx += n;
        }
        let q = deque([[0, 0, 0, 0]]);
        let visited = new Set([[0, 0, 0]]);
        while (q) {
            let [r, c, s, d] = q.popleft();
            if ((s === 0 && r === (n - 1) && c === (n - 2))) {
                console.log(d);
                return;
            }
            if (s === 0) {
                if (((c + 2) < n && grid[r][(c + 2)] === 0 && !_in([r, (c + 1), 0], visited))) {
                    visited.add([r, (c + 1), 0]);
                    q.push([r, (c + 1), 0, (d + 1)]);
                }
                if (((r + 1) < n && grid[(r + 1)][c] === 0 && grid[(r + 1)][(c + 1)] === 0 && !_in([(r + 1), c, 0], visited))) {
                    visited.add([(r + 1), c, 0]);
                    q.push([(r + 1), c, 0, (d + 1)]);
                }
                if (((r + 1) < n && grid[(r + 1)][c] === 0 && grid[(r + 1)][(c + 1)] === 0 && !_in([r, c, 1], visited))) {
                    visited.add([r, c, 1]);
                    q.push([r, c, 1, (d + 1)]);
                }
            } else {
                if (((c + 1) < n && grid[r][(c + 1)] === 0 && grid[(r + 1)][(c + 1)] === 0 && !_in([r, (c + 1), 1], visited))) {
                    visited.add([r, (c + 1), 1]);
                    q.push([r, (c + 1), 1, (d + 1)]);
                }
                if (((r + 2) < n && grid[(r + 2)][c] === 0 && !_in([(r + 1), c, 1], visited))) {
                    visited.add([(r + 1), c, 1]);
                    q.push([(r + 1), c, 1, (d + 1)]);
                }
                if (((c + 1) < n && grid[r][(c + 1)] === 0 && grid[(r + 1)][(c + 1)] === 0 && !_in([r, c, 0], visited))) {
                    visited.add([r, c, 0]);
                    q.push([r, c, 0, (d + 1)]);
                }
            }
        }
        console.log(-(1));
    }
}
main();
