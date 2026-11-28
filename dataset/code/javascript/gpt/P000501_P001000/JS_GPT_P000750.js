// Lexicographical Numbers Using Recursion
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function lex_numbers(n) {
    function dfs(cur) {
        if (cur > n) {
            return;
        }
        console.log(cur);
        for (const i of Array.from({length: 10}, (_, i) => i)) {
            if (((cur * 10) + i) <= n) {
                dfs(((cur * 10) + i));
            } else {
                break;
            }
        }
    }
    for (const i of Array.from({length: (10) - (1)}, (_, i) => (1) + i)) {
        if (i <= n) {
            dfs(i);
        }
    }
}
function main() {
    let tokens = _stdin_all.trim().split(/\s+/);
    if (tokens) {
        let n = parseInt(tokens[0], 10);
        lex_numbers(n);
    }
}
main();
