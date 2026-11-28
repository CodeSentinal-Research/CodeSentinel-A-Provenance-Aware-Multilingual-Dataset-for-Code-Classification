// Helper function to evaluate advantagecount for problem constraints.
function advantageCount(nums1, nums2) {
    const n = nums1.length;
    nums1.sort((a, b) => a - b);
    const sortedNums2 = nums2.map((val, idx) => [val, idx]).sort((a, b) => b[0] - a[0]);

    let l = 0, r = n - 1;
    const res = new Array(n);

    for (const [val, idx] of sortedNums2) {
        if (nums1[r] > val) {
            res[idx] = nums1[r--];
        } else {
            res[idx] = nums1[l++];
        }
    }
    return res;
}

module.exports = { advantageCount };