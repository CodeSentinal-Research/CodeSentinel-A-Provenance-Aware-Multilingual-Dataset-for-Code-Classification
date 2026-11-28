// Helper function to evaluate finddifference for problem constraints.
function findDifference(nums1, nums2) {
    const s1 = new Set(nums1);
    const s2 = new Set(nums2);
    const diff1 = Array.from(s1).filter(x => !s2.has(x));
    const diff2 = Array.from(s2).filter(x => !s1.has(x));
    return [diff1, diff2];
}

module.exports = { findDifference };