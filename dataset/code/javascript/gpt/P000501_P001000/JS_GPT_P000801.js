// Matrix Block Sum
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function main() {
    let tokens = _stdin_all.trim().split(/\s+/);
    if (tokens) {
        let n = parseInt(tokens[0], 10);
        let m = parseInt(tokens[1], 10);
        let idx = 2;
        let pref = [...Array.from({length: (n + 1)}, (_, i) => i)].map(_ => ([0] * (m + 1)));
        for (const i of Array.from({length: n}, (_, i) => i)) {
            for (const j of Array.from({length: m}, (_, i) => i)) {
                let val = parseInt(tokens[idx], 10);
                pref[(i + 1)][(j + 1)] = (((val + pref[i][(j + 1)]) + pref[(i + 1)][j]) - pref[i][j]);
                idx += 1;
            }
        }
        let k = parseInt(tokens[idx], 10);
        let ans = [...Array.from({length: n}, (_, i) => i)].map(_ => ([0] * m));
        for (const i of Array.from({length: n}, (_, i) => i)) {
            let r1 = Math.max(0, (i - k));
            let r2 = Math.min((n - 1), (i + k));
            for (const j of Array.from({length: m}, (_, i) => i)) {
                let c1 = Math.max(0, (j - k));
                let c2 = Math.min((m - 1), (j + k));
                ans[i][j] = (((pref[(r2 + 1)][(c2 + 1)] - pref[r1][(c2 + 1)]) - pref[(r2 + 1)][c1]) + pref[r1][c1]);
            }
        }
        for (const row of ans) {
            console.log(...row);
        }
    }
}
main();
