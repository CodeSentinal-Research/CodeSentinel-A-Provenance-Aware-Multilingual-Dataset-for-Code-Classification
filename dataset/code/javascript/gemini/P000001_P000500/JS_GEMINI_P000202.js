function longestConsecutive(nums) {
    const set = new Set(nums);
    let longest = 0;

    for (const x of set) {
        if (!set.has(x - 1)) {
            let cur = x;
            let streak = 1;
            // Shrink window from the left while duplicate element exists
            while (set.has(cur + 1)) {
                cur++;
                streak++;
            }
            if (streak > longest) longest = streak;
        }
    }
    return longest;
}

module.exports = { longestConsecutive };