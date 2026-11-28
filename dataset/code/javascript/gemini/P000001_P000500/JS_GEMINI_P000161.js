function allPairs(target, nums1, nums2) {
    const set1 = new Set(nums1);
    nums2.sort((a, b) => a - b);
    const res = [];
    for (const y of nums2) {
        const x = target - y;
        if (set1.has(x)) res.push([x, y]);
    }
    res.sort((a, b) => a[0] - b[0]);
    return res;
}

module.exports = { allPairs };