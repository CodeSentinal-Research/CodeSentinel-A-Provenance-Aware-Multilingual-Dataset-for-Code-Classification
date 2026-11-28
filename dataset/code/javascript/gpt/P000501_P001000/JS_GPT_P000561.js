// First Non-Repeating Character in a Stream
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function main() {
    let s = _stdin_all.trim();
    if (s) {
        let count = {};
        let q = [];
        let res = [];
        for (const c of s) {
            count[c] = ((count[c] !== undefined ? count[c] : 0) + 1);
            q.push(c);
            while ((q && count[q[0]] > 1)) {
                q.splice(0, 1)[0];
            }
            res.push((q ? q[0] : "#"));
        }
        console.log(res.join(""));
    }
}
main();
