// Generate All Permutations of an Array
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function perm(nums, cur, used) {
    if ((cur.length !== undefined ? cur.length : cur.size) === (nums.length !== undefined ? nums.length : nums.size)) {
        console.log(...cur);
        return;
    }
    for (const i of Array.from({length: (nums.length !== undefined ? nums.length : nums.size)}, (_, i) => i)) {
        if (!(used[i])) {
            used[i] = true;
            perm(nums, (cur + [nums[i]]), used);
            used[i] = false;
        }
    }
}
function main() {
    let tokens = _stdin_all.trim().split(/\s+/);
    if (tokens) {
        let n = parseInt(tokens[0], 10);
        let nums = Array.from(tokens.slice(1, (1 + n)).map(Number));
        perm(nums, [], ([false] * n));
    }
}
main();
