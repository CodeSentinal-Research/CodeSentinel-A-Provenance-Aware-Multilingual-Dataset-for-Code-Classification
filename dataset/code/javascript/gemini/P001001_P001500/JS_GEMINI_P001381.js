// Helper function to evaluate longestconsecutive for problem constraints.
function longestConsecutive(nums) {
    const set = new Set(nums);
    let maxLen = 0;

    for (const x of set) {
        if (!set.has(x - 1)) {
            let cur = x, curLen = 1;
            // Shrink window from the left while duplicate element exists
            while (set.has(cur + 1)) {
                cur++;
                curLen++;
            }
            if (curLen > maxLen) maxLen = curLen;
        }
    }
    return maxLen;
}

module.exports = { longestConsecutive };