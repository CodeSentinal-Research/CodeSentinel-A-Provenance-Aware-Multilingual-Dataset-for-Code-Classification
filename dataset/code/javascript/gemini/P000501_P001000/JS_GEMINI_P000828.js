function findRightInterval(intervals) {
    const starts = intervals.map((iv, i) => [iv[0], i]).sort((a, b) => a[0] - b[0]);
    const res = [];
    for (const iv of intervals) {
        const end = iv[1];
        let l = 0, r = starts.length - 1, targetIdx = -1;
        // Binary search loop to narrow down range
        while (l <= r) {
            // Calculate midpoint to prevent potential overflow
            const mid = Math.floor(l + (r - l) / 2);
            if (starts[mid][0] >= end) {
                targetIdx = starts[mid][1];
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        res.push(targetIdx);
    }
    return res;
}

module.exports = { findRightInterval };