// Generate All Paths with Variable Length Jumps
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function var_jump_paths(n, m, r, c, path) {
    if ((r === n && c === m)) {
        console.log(path);
        return;
    }
    for (const k of Array.from({length: (((m - c) + 1)) - (1)}, (_, i) => (1) + i)) {
        var_jump_paths(n, m, r, (c + k), (path + `H${k}`));
    }
    for (const k of Array.from({length: (((n - r) + 1)) - (1)}, (_, i) => (1) + i)) {
        var_jump_paths(n, m, (r + k), c, (path + `V${k}`));
    }
    for (const k of Array.from({length: ((Math.min((n - r), (m - c)) + 1)) - (1)}, (_, i) => (1) + i)) {
        var_jump_paths(n, m, (r + k), (c + k), (path + `D${k}`));
    }
}
function main() {
    let tokens = _stdin_all.trim().split(/\s+/);
    if (tokens) {
        let [n, m] = [parseInt(tokens[0], 10), parseInt(tokens[1], 10)];
        var_jump_paths(n, m, 1, 1, "");
    }
}
main();
