// Beautiful Towers II
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
        let left = ([0] * n);
        let st = [];
        for (const i of Array.from({length: n}, (_, i) => i)) {
            while ((st && h[st[-(1)]] >= h[i])) {
                st.pop();
            }
            if (st) {
                left[i] = (left[st[-(1)]] + (h[i] * (i - st[-(1)])));
            } else {
                left[i] = (h[i] * (i + 1));
            }
            st.push(i);
        }
        let right = ([0] * n);
        st = [];
        for (const i of _py_range((n - 1), -(1), -(1))) {
            while ((st && h[st[-(1)]] >= h[i])) {
                st.pop();
            }
            if (st) {
                right[i] = (right[st[-(1)]] + (h[i] * (st[-(1)] - i)));
            } else {
                right[i] = (h[i] * (n - i));
            }
            st.push(i);
        }
        let max_sum = Math.max(...[...Array.from({length: n}, (_, i) => i)].map(i => ((left[i] + right[i]) - h[i])));
        console.log(max_sum);
    }
}
main();
