// Helper function to evaluate mostfrequent for problem constraints.
function mostFrequent(nums, key) {
    const map = new Map();
    let maxCount = 0, bestTarget = 0;

    for (let i = 0; i < nums.length - 1; i++) {
        if (nums[i] === key) {
            const target = nums[i + 1];
            const cnt = (map.get(target) || 0) + 1;
            map.set(target, cnt);
            if (cnt > maxCount) {
                maxCount = cnt;
                bestTarget = target;
            }
        }
    }
    return bestTarget;
}

module.exports = { mostFrequent };