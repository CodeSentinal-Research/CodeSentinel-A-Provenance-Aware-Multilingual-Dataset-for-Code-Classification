// Partition Array into K Equal Sum Subsets
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function can_partition_k_subsets(nums, k) {
    let total = nums.reduce((a, b) => a + b, 0);
    if (((total % k) !== 0 || (nums.length !== undefined ? nums.length : nums.size) < k)) {
        return false;
    }
    let target = Math.floor(total / k);
    nums.sort();
    if (nums[0] > target) {
        return false;
    }
    let subsets = ([0] * k);
    function backtrack(idx) {
        if (idx === (nums.length !== undefined ? nums.length : nums.size)) {
            return true;
        }
        for (const i of Array.from({length: k}, (_, i) => i)) {
            if ((subsets[i] + nums[idx]) <= target) {
                subsets[i] += nums[idx];
                if (backtrack((idx + 1))) {
                    return true;
                }
                subsets[i] -= nums[idx];
            }
            if (subsets[i] === 0) {
                break;
            }
        }
        return false;
    }
    return backtrack(0);
}
function main() {
    let tokens = _stdin_all.trim().split(/\s+/);
    if (tokens) {
        let n = parseInt(tokens[0], 10);
        let nums = Array.from(tokens.slice(1, (1 + n)).map(Number));
        let k = parseInt(tokens[(1 + n)], 10);
        console.log((can_partition_k_subsets(nums, k) ? "true" : "false"));
    }
}
main();
