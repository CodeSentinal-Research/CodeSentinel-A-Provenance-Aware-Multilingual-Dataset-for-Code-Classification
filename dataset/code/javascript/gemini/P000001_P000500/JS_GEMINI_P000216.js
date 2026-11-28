function findShortestSubArray(nums) {
    const first = new Map();
    const last = new Map();
    const count = new Map();
    let degree = 0;

    for (let i = 0; i < nums.length; i++) {
        const x = nums[i];
        if (!first.has(x)) first.set(x, i);
        last.set(x, i);
        const cnt = (count.get(x) || 0) + 1;
        count.set(x, cnt);
        if (cnt > degree) degree = cnt;
    }

    let minLen = nums.length;
    for (const [x, cnt] of count.entries()) {
        if (cnt === degree) {
            const len = last.get(x) - first.get(x) + 1;
            if (len < minLen) minLen = len;
        }
    }
    return minLen;
}

module.exports = { findShortestSubArray };