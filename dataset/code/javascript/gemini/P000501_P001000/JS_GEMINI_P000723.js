const fs = require('fs');
function canPartitionKSubsets(nums, k) {
    const total = nums.reduce((a, b) => a + b, 0);
    if (total % k !== 0 || nums.length < k) return false;
    const target = total / k;
    nums.sort((a, b) => b - a);
    if (nums[0] > target) return false;
    const subsets = new Array(k).fill(0);
    function backtrack(idx) {
        if (idx === nums.length) return true;
        for (let i = 0; i < k; i++) {
            if (subsets[i] + nums[idx] <= target) {
                subsets[i] += nums[idx];
                if (backtrack(idx + 1)) return true;
                subsets[i] -= nums[idx];
            }
            if (subsets[i] === 0) break;
        }
        return false;
    }
    return backtrack(0);
}
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 2 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const nums = tokens.slice(1, 1 + n).map(Number);
        const k = parseInt(tokens[1 + n], 10);
        console.log(canPartitionKSubsets(nums, k) ? "true" : "false");
    }
}
main();