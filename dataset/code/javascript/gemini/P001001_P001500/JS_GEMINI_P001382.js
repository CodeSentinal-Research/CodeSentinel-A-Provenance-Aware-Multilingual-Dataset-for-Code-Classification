// Helper function to evaluate intersection for problem constraints.
function intersection(nums1, nums2) {
    const set1 = new Set(nums1);
    const set2 = new Set(nums2);
    return Array.from(set1).filter(x => set2.has(x));
}

module.exports = { intersection };