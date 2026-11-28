// Generate All Subsequences of a String
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function gen_subseq(s, idx, cur, res) {
    if (idx === (s.length !== undefined ? s.length : s.size)) {
        res.push(cur);
        return;
    }
    gen_subseq(s, (idx + 1), cur, res);
    gen_subseq(s, (idx + 1), (cur + s[idx]), res);
}
function main() {
    let tokens = _stdin_all.trim().split(/\s+/);
    if (tokens) {
        let s = tokens[0];
        let res = [];
        gen_subseq(s, 0, "", res);
        res.sort();
        for (const x of res) {
            console.log(x);
        }
    }
}
main();
