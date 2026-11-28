// Maze Paths with Diagonal Moves
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function diagonal_paths(n, m, r, c, path) {
    if ((r === n && c === m)) {
        console.log(path);
        return;
    }
    if ((r < n && c < m)) {
        diagonal_paths(n, m, (r + 1), (c + 1), (path + "D"));
    }
    if (c < m) {
        diagonal_paths(n, m, r, (c + 1), (path + "H"));
    }
    if (r < n) {
        diagonal_paths(n, m, (r + 1), c, (path + "V"));
    }
}
function main() {
    let tokens = _stdin_all.trim().split(/\s+/);
    if (tokens) {
        let [n, m] = [parseInt(tokens[0], 10), parseInt(tokens[1], 10)];
        diagonal_paths(n, m, 1, 1, "");
    }
}
main();
