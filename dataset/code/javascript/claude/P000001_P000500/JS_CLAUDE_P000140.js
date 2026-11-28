function unionArrays(nums1, nums2) {
    return [...new Set([...nums1, ...nums2])].sort((a, b) => a - b);
}
module.exports = { unionArrays };
