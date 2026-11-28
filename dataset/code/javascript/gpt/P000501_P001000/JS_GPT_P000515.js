// Car Fleet II
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
        let cars = [];
        let idx = 1;
        for (const _ of Array.from({length: n}, (_, i) => i)) {
            cars.push([parseFloat(tokens[idx]), parseFloat(tokens[(idx + 1)])]);
            idx += 2;
        }
        let ans = ([-(1.0)] * n);
        let stack = [];
        for (const i of _py_range((n - 1), -(1), -(1))) {
            let [p, s] = cars[i];
            while (stack) {
                let j = stack[-(1)];
                let [pj, sj] = cars[j];
                if ((s <= sj || (ans[j] > 0 && ((pj - p) / (s - sj)) >= ans[j]))) {
                    stack.pop();
                } else {
                    break;
                }
            }
            if (stack) {
                j = stack[-(1)];
                [pj, sj] = cars[j];
                ans[i] = ((pj - p) / (s - sj));
            }
            stack.push(i);
        }
        console.log(...[...ans].map(x => (x > 0 ? `${x}` : "-1.00000")));
    }
}
main();
