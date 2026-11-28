// Subsets II
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function subsets_with_dup(nums, idx, cur) {
    console.log(...cur);
    for (const i of Array.from({length: ((nums.length !== undefined ? nums.length : nums.size)) - (idx)}, (_, i) => (idx) + i)) {
        if ((i > idx && nums[i] === nums[(i - 1)])) {
            continue;
        }
        subsets_with_dup(nums, (i + 1), (cur + [nums[i]]));
    }
}
function main() {
    let tokens = _stdin_all.trim().split(/\s+/);
    if (tokens) {
        let n = parseInt(tokens[0], 10);
        let nums = [...Array.from(tokens.slice(1, (1 + n)).map(Number))].sort((a, b) => a < b ? -1 : a > b ? 1 : 0);
        subsets_with_dup(nums, 0, []);
    }
}
main();
