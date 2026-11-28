// Generate All Case Permutations of a String
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function case_perm(s, idx, cur, res) {
    if (idx === (s.length !== undefined ? s.length : s.size)) {
        res.push(cur);
        return;
    }
    let ch = s[idx];
    if (/^[a-zA-Z]+$/.test(ch)) {
        case_perm(s, (idx + 1), (cur + ch.toLowerCase()), res);
        case_perm(s, (idx + 1), (cur + ch.toUpperCase()), res);
    } else {
        case_perm(s, (idx + 1), (cur + ch), res);
    }
}
function main() {
    let tokens = _stdin_all.trim().split(/\s+/);
    if (tokens) {
        let s = tokens[0];
        let res = [];
        case_perm(s, 0, "", res);
        res.sort();
        for (const p of res) {
            console.log(p);
        }
    }
}
main();
