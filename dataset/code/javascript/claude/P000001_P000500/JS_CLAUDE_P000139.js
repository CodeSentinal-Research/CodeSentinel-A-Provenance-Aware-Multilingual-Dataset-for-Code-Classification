function intersection(nums1, nums2) {
    const s1 = new Set(nums1);
    return [...new Set(nums2.filter(x => s1.has(x)))];
}
module.exports = { intersection };
