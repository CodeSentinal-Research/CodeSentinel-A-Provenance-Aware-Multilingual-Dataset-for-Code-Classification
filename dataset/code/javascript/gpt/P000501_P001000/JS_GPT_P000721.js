// Generate All Increasing Subsequences
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function find_subseq(nums, idx, cur, res) {
    if ((cur.length !== undefined ? cur.length : cur.size) >= 2) {
        res.add(tuple(cur));
    }
    for (const i of Array.from({length: ((nums.length !== undefined ? nums.length : nums.size)) - (idx)}, (_, i) => (idx) + i)) {
        if ((!(cur) || nums[i] >= cur[-(1)])) {
            find_subseq(nums, (i + 1), (cur + [nums[i]]), res);
        }
    }
}
function main() {
    let tokens = _stdin_all.trim().split(/\s+/);
    if (tokens) {
        let n = parseInt(tokens[0], 10);
        let nums = Array.from(tokens.slice(1, (1 + n)).map(Number));
        let res = new Set();
        find_subseq(nums, 0, [], res);
        for (const seq of [...res].sort((a, b) => a < b ? -1 : a > b ? 1 : 0)) {
            console.log(...seq);
        }
    }
}
main();
