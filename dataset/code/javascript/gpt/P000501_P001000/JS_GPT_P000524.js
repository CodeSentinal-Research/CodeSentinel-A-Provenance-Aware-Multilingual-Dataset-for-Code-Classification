// Beautiful Towers I
const fs = require("fs");
function _py_range(start, stop, step = 1) { const res = []; if (step > 0) { for (let i = start; i < stop; i += step) res.push(i); } else { for (let i = start; i > stop; i += step) res.push(i); } return res; }
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function main() {
    let tokens = _stdin_all.trim().split(/\s+/);
    if (tokens) {
        let n = parseInt(tokens[0], 10);
        let h = Array.from(tokens.slice(1, (1 + n)).map(Number));
        let max_sum = 0;
        for (const peak of Array.from({length: n}, (_, i) => i)) {
            let curr_sum = h[peak];
            let cur = h[peak];
            for (const i of _py_range((peak - 1), -(1), -(1))) {
                cur = Math.min(cur, h[i]);
                curr_sum += cur;
            }
            cur = h[peak];
            for (const i of Array.from({length: (n) - ((peak + 1))}, (_, i) => ((peak + 1)) + i)) {
                cur = Math.min(cur, h[i]);
                curr_sum += cur;
            }
            max_sum = Math.max(max_sum, curr_sum);
        }
        console.log(max_sum);
    }
}
main();
