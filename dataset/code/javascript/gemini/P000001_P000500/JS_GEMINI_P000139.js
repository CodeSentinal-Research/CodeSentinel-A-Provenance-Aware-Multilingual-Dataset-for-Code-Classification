function intersection(nums1, nums2) {
    const set1 = new Set(nums1);
    const inter = new Set();
    for (const x of nums2) {
        if (set1.has(x)) inter.add(x);
    }
    return Array.from(inter);
}

module.exports = { intersection };