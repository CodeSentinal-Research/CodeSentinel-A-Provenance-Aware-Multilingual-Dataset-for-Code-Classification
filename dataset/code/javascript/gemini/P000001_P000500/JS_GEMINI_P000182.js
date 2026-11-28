function mostFrequent(nums) {
    const freq = new Map();
    let maxCnt = 0, best = nums[0];
    for (const x of nums) {
        const cnt = (freq.get(x) || 0) + 1;
        freq.set(x, cnt);
        if (cnt > maxCnt) {
            maxCnt = cnt;
            best = x;
        }
    }
    return best;
}

module.exports = { mostFrequent };