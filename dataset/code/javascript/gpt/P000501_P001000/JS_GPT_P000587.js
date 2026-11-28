// Merge K Sorted Linked Lists
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function main() {
    let tokens = _stdin_all.trim().split(/\s+/);
    if (tokens) {
        let k = parseInt(tokens[0], 10);
        let idx = 1;
        let all_vals = [];
        for (const _ of Array.from({length: k}, (_, i) => i)) {
            let size = parseInt(tokens[idx], 10);
            all_vals.push(...tokens.slice((idx + 1), ((idx + 1) + size)).map(Number));
            idx += (1 + size);
        }
        all_vals.sort();
        console.log(...all_vals);
    }
}
main();
