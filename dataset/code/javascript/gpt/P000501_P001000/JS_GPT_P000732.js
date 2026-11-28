// Rat in a Maze
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function rat_in_maze(grid, n) {
    if ((grid[0][0] === 0 || grid[(n - 1)][(n - 1)] === 0)) {
        return [];
    }
    let res = [];
    let vis = [...Array.from({length: n}, (_, i) => i)].map(_ => ([false] * n));
    let moves = [["D", 1, 0], ["L", 0, -(1)], ["R", 0, 1], ["U", -(1), 0]];
    function backtrack(r, c, path) {
        if ((r === (n - 1) && c === (n - 1))) {
            res.push(path);
            return;
        }
        vis[r][c] = true;
        for (const [move, dr, dc] of moves) {
            let [nr, nc] = [(r + dr), (c + dc)];
            if ((0 <= nr && nr < n && 0 <= nc && nc < n && grid[nr][nc] === 1 && !(vis[nr][nc]))) {
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
        let grid = [];
        let idx = 1;
        for (const _ of Array.from({length: n}, (_, i) => i)) {
            grid.push(Array.from(tokens.slice(idx, (idx + n)).map(Number)));
            idx += n;
        }
        let paths = rat_in_maze(grid, n);
        for (const p of paths) {
            console.log(p);
        }
    }
}
main();
