// Print Numbers from 1 to N Without Loops
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function print_1_to_n(n) {
    if (n <= 0) {
        return [];
    }
    return (print_1_to_n((n - 1)) + [n]);
}
function main() {
    let tokens = _stdin_all.trim().split(/\s+/);
    if (tokens) {
        let n = parseInt(tokens[0], 10);
        console.log(...print_1_to_n(n));
    }
}
main();
