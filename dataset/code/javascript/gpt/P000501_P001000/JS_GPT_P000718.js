// Generate N-bit Gray Code
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function gray_code(n) {
    if (n === 0) {
        return ["0"];
    }
    if (n === 1) {
        return ["0", "1"];
    }
    let prev = gray_code((n - 1));
    return ([...prev].map(s => ("0" + s)) + [...[...prev].reverse()].map(s => ("1" + s)));
}
function main() {
    let tokens = _stdin_all.trim().split(/\s+/);
    if (tokens) {
        let n = parseInt(tokens[0], 10);
        for (const code of gray_code(n)) {
            console.log(code);
        }
    }
}
main();
