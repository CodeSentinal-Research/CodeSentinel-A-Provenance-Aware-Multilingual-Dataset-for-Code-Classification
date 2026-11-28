// Maximum Length Concatenated String with Unique Characters
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function max_length(words) {
    let masks = [];
    for (const w of words) {
        let m = 0;
        let dup = false;
        for (const ch of w) {
            let b = (1 << (ord(ch) - ord("a")));
            if ((m & b)) {
                dup = true;
                break;
            }
            m |= b;
        }
        if (!(dup)) {
            masks.push([m, (w.length !== undefined ? w.length : w.size)]);
        }
    }
    let ans = [0];
    function backtrack(idx, cur_m, cur_len) {
        ans[0] = Math.max(ans[0], cur_len);
        for (const i of Array.from({length: ((masks.length !== undefined ? masks.length : masks.size)) - (idx)}, (_, i) => (idx) + i)) {
            let [m, l] = masks[i];
            if (!((cur_m & m))) {
                backtrack((i + 1), (cur_m | m), (cur_len + l));
            }
        }
    }
    backtrack(0, 0, 0);
    return ans[0];
}
function main() {
    let tokens = _stdin_all.trim().split(/\s+/);
    if (tokens) {
        let n = parseInt(tokens[0], 10);
        let words = tokens.slice(1, (1 + n));
        console.log(max_length(words));
    }
}
main();
