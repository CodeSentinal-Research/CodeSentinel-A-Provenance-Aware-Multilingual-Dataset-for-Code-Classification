// Split String into Descending Consecutive Values
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function split_descending(s) {
    function backtrack(idx, prev) {
        if (idx === (s.length !== undefined ? s.length : s.size)) {
            return true;
        }
        let cur = 0;
        for (const i of Array.from({length: ((s.length !== undefined ? s.length : s.size)) - (idx)}, (_, i) => (idx) + i)) {
            cur = ((cur * 10) + parseInt(s[i], 10));
            if (cur === (prev - 1)) {
                if (backtrack((i + 1), cur)) {
                    return true;
                }
            } else {
                if (cur >= prev) {
                    break;
                }
            }
        }
        return false;
    }
    let first = 0;
    for (const i of Array.from({length: ((s.length !== undefined ? s.length : s.size) - 1)}, (_, i) => i)) {
        first = ((first * 10) + parseInt(s[i], 10));
        if (backtrack((i + 1), first)) {
            return true;
        }
    }
    return false;
}
function main() {
    let tokens = _stdin_all.trim().split(/\s+/);
    if (tokens) {
        console.log((split_descending(tokens[0]) ? "true" : "false"));
    }
}
main();
