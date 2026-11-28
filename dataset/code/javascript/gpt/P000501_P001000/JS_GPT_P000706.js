// Generate All Binary Strings of Length N
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function gen_bin(n, cur) {
    if ((cur.length !== undefined ? cur.length : cur.size) === n) {
        console.log(cur);
        return;
    }
    gen_bin(n, (cur + "0"));
    gen_bin(n, (cur + "1"));
}
function main() {
    let tokens = _stdin_all.trim().split(/\s+/);
    if (tokens) {
        let n = parseInt(tokens[0], 10);
        gen_bin(n, "");
    }
}
main();
