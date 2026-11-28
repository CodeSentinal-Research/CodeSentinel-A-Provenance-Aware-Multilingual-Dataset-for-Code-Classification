// Flood Fill All Paths
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function flood_fill_paths(grid, n, m) {
    if ((grid[0][0] === 0 || grid[(n - 1)][(m - 1)] === 0)) {
        return [];
    }
    let res = [];
    let vis = [...Array.from({length: n}, (_, i) => i)].map(_ => ([false] * m));
    let moves = [["D", 1, 0], ["L", 0, -(1)], ["R", 0, 1], ["U", -(1), 0]];
    function backtrack(r, c, path) {
        if ((r === (n - 1) && c === (m - 1))) {
            res.push(path);
            return;
        }
        vis[r][c] = true;
        for (const [move, dr, dc] of moves) {
            let [nr, nc] = [(r + dr), (c + dc)];
            if ((0 <= nr && nr < n && 0 <= nc && nc < m && grid[nr][nc] === 1 && !(vis[nr][nc]))) {
                backtrack(nr, nc, (path + move));
            }
        }
        vis[r][c] = false;
    }
    backtrack(0, 0, "");
    return [...res].sort((a, b) => a < b ? -1 : a > b ? 1 : 0);
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
        for (const p of flood_fill_paths(grid, n, m)) {
            console.log(p);
        }
    }
}
main();
