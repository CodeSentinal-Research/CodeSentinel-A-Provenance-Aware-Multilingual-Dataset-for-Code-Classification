// 2D Prefix Sum Matrix
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
        let grid = [];
        for (const _ of Array.from({length: n}, (_, i) => i)) {
            grid.push(Array.from(tokens.slice(idx, (idx + m)).map(Number)));
            idx += m;
        }
        let pref = [...Array.from({length: n}, (_, i) => i)].map(_ => ([0] * m));
        for (const i of Array.from({length: n}, (_, i) => i)) {
            for (const j of Array.from({length: m}, (_, i) => i)) {
                pref[i][j] = grid[i][j];
                if (i > 0) {
                    pref[i][j] += pref[(i - 1)][j];
                }
                if (j > 0) {
                    pref[i][j] += pref[i][(j - 1)];
                }
                if ((i > 0 && j > 0)) {
                    pref[i][j] -= pref[(i - 1)][(j - 1)];
                }
            }
        }
        for (const row of pref) {
            console.log(...row);
        }
    }
}
main();
