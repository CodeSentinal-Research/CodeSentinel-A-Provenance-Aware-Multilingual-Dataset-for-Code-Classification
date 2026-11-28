// Generate All Increasing Numbers with N Digits
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function inc_numbers(n, start, cur) {
    if ((cur.length !== undefined ? cur.length : cur.size) === n) {
        console.log(cur);
        return;
    }
    for (const d of Array.from({length: (10) - (start)}, (_, i) => (start) + i)) {
        inc_numbers(n, (d + 1), (cur + String(d)));
    }
}
function main() {
    let tokens = _stdin_all.trim().split(/\s+/);
    if (tokens) {
        let n = parseInt(tokens[0], 10);
        if (n === 1) {
            console.log(0);
        }
        inc_numbers(n, 1, "");
    }
}
main();
