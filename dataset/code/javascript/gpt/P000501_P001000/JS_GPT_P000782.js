// Count Elements in Range
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function main() {
    let tokens = _stdin_all.trim().split(/\s+/);
    if (tokens) {
        let n = parseInt(tokens[0], 10);
        let nums = Array.from(tokens.slice(1, (1 + n)).map(Number));
        let q = parseInt(tokens[(1 + n)], 10);
        let idx = (2 + n);
        for (const _ of Array.from({length: q}, (_, i) => i)) {
            let [l, r] = [parseInt(tokens[idx], 10), parseInt(tokens[(idx + 1)], 10)];
            console.log(((r - l) + 1));
            idx += 2;
        }
    }
}
main();
