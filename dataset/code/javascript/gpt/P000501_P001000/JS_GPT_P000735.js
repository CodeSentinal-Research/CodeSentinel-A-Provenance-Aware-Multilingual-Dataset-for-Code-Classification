// Generate All K-Length Strings from Given Characters
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function gen_k_strings(chars, k, cur) {
    if ((cur.length !== undefined ? cur.length : cur.size) === k) {
        console.log(cur);
        return;
    }
    for (const c of chars) {
        gen_k_strings(chars, k, (cur + c));
    }
}
function main() {
    let tokens = _stdin_all.trim().split(/\s+/);
    if (tokens) {
        let n = parseInt(tokens[0], 10);
        let chars = [...tokens.slice(1, (1 + n))].sort((a, b) => a < b ? -1 : a > b ? 1 : 0);
        let k = parseInt(tokens[(1 + n)], 10);
        gen_k_strings(chars, k, "");
    }
}
main();
