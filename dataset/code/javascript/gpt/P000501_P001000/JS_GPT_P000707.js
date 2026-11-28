// Generate All Strings of Balanced Parentheses
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function gen_par(n, o, c, cur) {
    if ((cur.length !== undefined ? cur.length : cur.size) === (2 * n)) {
        console.log(cur);
        return;
    }
    if (o < n) {
        gen_par(n, (o + 1), c, (cur + "("));
    }
    if (c < o) {
        gen_par(n, o, (c + 1), (cur + ")"));
    }
}
function main() {
    let tokens = _stdin_all.trim().split(/\s+/);
    if (tokens) {
        let n = parseInt(tokens[0], 10);
        gen_par(n, 0, 0, "");
    }
}
main();
