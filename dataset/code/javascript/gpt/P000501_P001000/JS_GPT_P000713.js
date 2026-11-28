// Combination Sum II
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function comb_sum2(cands, target, idx, cur) {
    if (target === 0) {
        console.log(...cur);
        return;
    }
    for (const i of Array.from({length: ((cands.length !== undefined ? cands.length : cands.size)) - (idx)}, (_, i) => (idx) + i)) {
        if ((i > idx && cands[i] === cands[(i - 1)])) {
            continue;
        }
        if (cands[i] > target) {
            break;
        }
        comb_sum2(cands, (target - cands[i]), (i + 1), (cur + [cands[i]]));
    }
}
function main() {
    let tokens = _stdin_all.trim().split(/\s+/);
    if (tokens) {
        let n = parseInt(tokens[0], 10);
        let cands = [...Array.from(tokens.slice(1, (1 + n)).map(Number))].sort((a, b) => a < b ? -1 : a > b ? 1 : 0);
        let target = parseInt(tokens[(1 + n)], 10);
        comb_sum2(cands, target, 0, []);
    }
}
main();
