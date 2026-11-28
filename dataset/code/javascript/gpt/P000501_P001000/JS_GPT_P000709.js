// Generate All Permutations of a String
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function perm(s, cur, used, res) {
    if ((cur.length !== undefined ? cur.length : cur.size) === (s.length !== undefined ? s.length : s.size)) {
        res.push(cur);
        return;
    }
    for (const i of Array.from({length: (s.length !== undefined ? s.length : s.size)}, (_, i) => i)) {
        if (!(used[i])) {
            used[i] = true;
            perm(s, (cur + s[i]), used, res);
            used[i] = false;
        }
    }
}
function main() {
    let tokens = _stdin_all.trim().split(/\s+/);
    if (tokens) {
        let s = [...tokens[0]].sort((a, b) => a < b ? -1 : a > b ? 1 : 0);
        let res = [];
        perm(s, "", ([false] * (s.length !== undefined ? s.length : s.size)), res);
        for (const p of res) {
            console.log(p);
        }
    }
}
main();
