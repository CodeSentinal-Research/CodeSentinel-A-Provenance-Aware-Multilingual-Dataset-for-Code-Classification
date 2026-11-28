// Palindrome Partitioning
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function is_pal(s) {
    return s === s.slice(0);
}
function pal_partition(s, start, cur) {
    if (start === (s.length !== undefined ? s.length : s.size)) {
        console.log(...cur);
        return;
    }
    for (const end of Array.from({length: (((s.length !== undefined ? s.length : s.size) + 1)) - ((start + 1))}, (_, i) => ((start + 1)) + i)) {
        let sub = s.slice(start, end);
        if (is_pal(sub)) {
            pal_partition(s, end, (cur + [sub]));
        }
    }
}
function main() {
    let tokens = _stdin_all.trim().split(/\s+/);
    if (tokens) {
        pal_partition(tokens[0], 0, []);
    }
}
main();
