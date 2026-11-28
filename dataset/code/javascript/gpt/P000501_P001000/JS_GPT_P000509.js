// Clear Digits from String
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function main() {
    let s = _stdin_all.trim();
    let st = [];
    for (const c of s) {
        if (/^\d+$/.test(c)) {
            if (st) {
                st.pop();
            }
        } else {
            st.push(c);
        }
    }
    console.log(st.join(""));
}
main();
