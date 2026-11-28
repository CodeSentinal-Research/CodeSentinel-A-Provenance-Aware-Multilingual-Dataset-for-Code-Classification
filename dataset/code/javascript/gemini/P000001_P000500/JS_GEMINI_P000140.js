function union(nums1, nums2) {
    const set = new Set([...nums1, ...nums2]);
    return Array.from(set);
}

module.exports = { union };