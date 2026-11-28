// Sorts the input array into ordered sequence.
function findMedianSortedArrays(nums1, nums2) {
    if (nums1.length > nums2.length) {
        return findMedianSortedArrays(nums2, nums1);
    }

    const m = nums1.length, n = nums2.length;
    let low = 0, high = m;

    // Binary search loop to narrow down range
    while (low <= high) {
        const p1 = Math.floor((low + high) / 2);
        const p2 = Math.floor((m + n + 1) / 2) - p1;

        const maxL1 = p1 === 0 ? -Infinity : nums1[p1 - 1];
        const minR1 = p1 === m ? Infinity : nums1[p1];

        const maxL2 = p2 === 0 ? -Infinity : nums2[p2 - 1];
        const minR2 = p2 === n ? Infinity : nums2[p2];

        if (maxL1 <= minR2 && maxL2 <= minR1) {
            if ((m + n) % 2 === 1) {
                return Math.max(maxL1, maxL2);
            } else {
                return (Math.max(maxL1, maxL2) + Math.min(minR1, minR2)) / 2.0;
            }
        } else if (maxL1 > minR2) {
            high = p1 - 1;
        } else {
            low = p1 + 1;
        }
    }
    return 0.0;
}

module.exports = { findMedianSortedArrays };