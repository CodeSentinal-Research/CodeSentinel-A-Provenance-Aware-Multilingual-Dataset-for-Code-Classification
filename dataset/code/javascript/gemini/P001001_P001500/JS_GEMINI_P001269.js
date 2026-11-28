// Helper function to evaluate ispossibledivide for problem constraints.
function isPossibleDivide(nums, k) {
    if (nums.length % k !== 0) return false;
    nums.sort((a, b) => a - b);
    const count = new Map();
    for (const x of nums) count.set(x, (count.get(x) || 0) + 1);

    for (const x of nums) {
        const freq = count.get(x) || 0;
        if (freq > 0) {
            for (let i = 0; i < k; i++) {
                const cur = count.get(x + i) || 0;
                if (cur < freq) return false;
                count.set(x + i, cur - freq);
            }
        }
    }
    return true;
}

module.exports = { isPossibleDivide };