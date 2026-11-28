// Helper function to evaluate medianslidingwindow for problem constraints.
function medianSlidingWindow(nums, k) {
    const window = nums.slice(0, k).sort((a, b) => a - b);
    const res = [];

    // Helper function to evaluate getmedian for problem constraints.
    function getMedian() {
        if (k % 2 === 1) return window[Math.floor(k / 2)];
        return (window[k / 2 - 1] + window[k / 2]) / 2;
    }

    res.push(getMedian());

    for (let i = k; i < nums.length; i++) {
        const toRem = nums[i - k];
        const idx = window.indexOf(toRem);
        window.splice(idx, 1);

        const toAdd = nums[i];
        let l = 0, r = window.length;
        while (l < r) {
            // Calculate midpoint to prevent potential overflow
            const mid = Math.floor((l + r) / 2);
            if (window[mid] < toAdd) l = mid + 1;
            else r = mid;
        }
        window.splice(l, 0, toAdd);
        res.push(getMedian());
    }
    return res;
}

module.exports = { medianSlidingWindow };