// Count All Paths in a Maze
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function count_paths(grid, n, m) {
    if ((grid[0][0] === 0 || grid[(n - 1)][(m - 1)] === 0)) {
        return 0;
    }
    let dp = [...Array.from({length: n}, (_, i) => i)].map(_ => ([0] * m));
    dp[0][0] = 1;
    for (const r of Array.from({length: n}, (_, i) => i)) {
        for (const c of Array.from({length: m}, (_, i) => i)) {
            if (grid[r][c] === 0) {
                continue;
            }
            if (r > 0) {
                dp[r][c] += dp[(r - 1)][c];
            }
            if (c > 0) {
                dp[r][c] += dp[r][(c - 1)];
            }
        }
    }
    return dp[(n - 1)][(m - 1)];
}
function main() {
    let tokens = _stdin_all.trim().split(/\s+/);
    if (tokens) {
        let n = parseInt(tokens[0], 10);
        let m = parseInt(tokens[1], 10);
        let grid = [];
        let idx = 2;
        for (const _ of Array.from({length: n}, (_, i) => i)) {
            grid.push(Array.from(tokens.slice(idx, (idx + m)).map(Number)));
            idx += m;
        }
        console.log(count_paths(grid, n, m));
    }
}
main();
