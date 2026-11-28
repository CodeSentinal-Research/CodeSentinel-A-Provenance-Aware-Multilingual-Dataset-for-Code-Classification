// Rotting Oranges
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function main() {
    let tokens = _stdin_all.trim().split(/\s+/);
    if (tokens) {
        let m = parseInt(tokens[0], 10);
        let n = parseInt(tokens[1], 10);
        let idx = 2;
        let grid = [];
        let q = deque();
        let fresh = 0;
        for (const r of Array.from({length: m}, (_, i) => i)) {
            let row = [];
            for (const c of Array.from({length: n}, (_, i) => i)) {
                let val = parseInt(tokens[idx], 10);
                row.push(val);
                if (val === 2) {
                    q.push([r, c, 0]);
                } else {
                    if (val === 1) {
                        fresh += 1;
                    }
                }
                idx += 1;
            }
            grid.push(row);
        }
        let mins = 0;
        while (q) {
            let [r, c, d] = q.popleft();
            mins = Math.max(mins, d);
            for (const [dr, dc] of [[-(1), 0], [1, 0], [0, -(1)], [0, 1]]) {
                let [nr, nc] = [(r + dr), (c + dc)];
                if ((0 <= nr && nr < m && 0 <= nc && nc < n && grid[nr][nc] === 1)) {
                    grid[nr][nc] = 2;
                    fresh -= 1;
                    q.push([nr, nc, (d + 1)]);
                }
            }
        }
        console.log((fresh === 0 ? mins : -(1)));
    }
}
main();
