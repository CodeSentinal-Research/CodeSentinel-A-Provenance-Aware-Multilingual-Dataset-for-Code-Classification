// Decode String at Index
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function decode_at_index(s, k) {
    let size = 0;
    for (const c of s) {
        if (/^\d+$/.test(c)) {
            size *= parseInt(c, 10);
        } else {
            size += 1;
        }
    }
    for (const c of [...s].reverse()) {
        k %= size;
        if ((k === 0 && /^[a-zA-Z]+$/.test(c))) {
            return c;
        }
        if (/^\d+$/.test(c)) {
            size = Math.floor(size / (parseInt(c, 10)));
        } else {
            size -= 1;
        }
    }
}
function main() {
    let tokens = _stdin_all.trim().split(/\s+/);
    if (tokens) {
        let s = tokens[0];
        let k = parseInt(tokens[1], 10);
        console.log(decode_at_index(s, k));
    }
}
main();
