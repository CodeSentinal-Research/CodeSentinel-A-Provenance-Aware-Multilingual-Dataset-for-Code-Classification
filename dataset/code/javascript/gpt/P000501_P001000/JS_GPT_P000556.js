// Minimum Number of Visited Cells in a Grid
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
        for (const _ of Array.from({length: m}, (_, i) => i)) {
            grid.push(Array.from(tokens.slice(idx, (idx + n)).map(Number)));
            idx += n;
        }
        if ((m === 1 && n === 1)) {
            console.log(1);
            return;
        }
        let dist = [...Array.from({length: m}, (_, i) => i)].map(_ => ([parseFloat("inf")] * n));
        dist[0][0] = 1;
        let max_r = ([0] * m);
        let max_c = ([0] * n);
        let q = deque([[0, 0]]);
        while (q) {
            let [r, c] = q.popleft();
            let d = dist[r][c];
            let k = grid[r][c];
            let start_c = Math.max((c + 1), (max_r[r] + 1));
            let end_c = Math.min((c + k), (n - 1));
            for (const nc of Array.from({length: ((end_c + 1)) - (start_c)}, (_, i) => (start_c) + i)) {
                if (dist[r][nc] === parseFloat("inf")) {
                    dist[r][nc] = (d + 1);
                    if ((r === (m - 1) && nc === (n - 1))) {
                        console.log((d + 1));
                        return;
                    }
                    q.push([r, nc]);
                }
            }
            max_r[r] = Math.max(max_r[r], end_c);
            let start_r = Math.max((r + 1), (max_c[c] + 1));
            let end_r = Math.min((r + k), (m - 1));
            for (const nr of Array.from({length: ((end_r + 1)) - (start_r)}, (_, i) => (start_r) + i)) {
                if (dist[nr][c] === parseFloat("inf")) {
                    dist[nr][c] = (d + 1);
                    if ((nr === (m - 1) && c === (n - 1))) {
                        console.log((d + 1));
                        return;
                    }
                    q.push([nr, c]);
                }
            }
            max_c[c] = Math.max(max_c[c], end_r);
        }
        console.log((dist[(m - 1)][(n - 1)] !== parseFloat("inf") ? dist[(m - 1)][(n - 1)] : -(1)));
    }
}
main();
