// Generate All Binary Strings Without Consecutive Ones
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function gen_no_cons_ones(n, cur) {
    if ((cur.length !== undefined ? cur.length : cur.size) === n) {
        console.log(cur);
        return;
    }
    gen_no_cons_ones(n, (cur + "0"));
    if ((!(cur) || cur[-(1)] !== "1")) {
        gen_no_cons_ones(n, (cur + "1"));
    }
}
function main() {
    let tokens = _stdin_all.trim().split(/\s+/);
    if (tokens) {
        let n = parseInt(tokens[0], 10);
        gen_no_cons_ones(n, "");
    }
}
main();
