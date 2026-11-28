// Tug of War Partition
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function tug_of_war(nums) {
    let n = (nums.length !== undefined ? nums.length : nums.size);
    let total = nums.reduce((a, b) => a + b, 0);
    let min_diff = [parseFloat("inf")];
    let best_part = [[]];
    let half = Math.floor(n / 2);
    function backtrack(idx, count, cur_sum, cur_part) {
        if (count === half) {
            let diff = Math.abs((total - (2 * cur_sum)));
            if (diff < min_diff[0]) {
                min_diff[0] = diff;
                best_part[0] = Array.from(cur_part);
            }
            return;
        }
        if ((idx === n || (half - count) > (n - idx))) {
            return;
        }
        backtrack((idx + 1), (count + 1), (cur_sum + nums[idx]), (cur_part + [nums[idx]]));
        backtrack((idx + 1), count, cur_sum, cur_part);
    }
    backtrack(0, 0, 0, []);
    return [min_diff[0], best_part[0]];
}
function main() {
    let tokens = _stdin_all.trim().split(/\s+/);
    if (tokens) {
        let n = parseInt(tokens[0], 10);
        let nums = Array.from(tokens.slice(1, (1 + n)).map(Number));
        let [diff, part] = tug_of_war(nums);
        console.log(diff);
        console.log(...part);
    }
}
main();
