function findMedianSortedArrays(nums1, nums2) {
    let merged = nums1.concat(nums2).sort((a, b) => a - b);
    let mid = Math.floor(merged.length / 2);

    if (merged.length % 2 === 0) {
        return (merged[mid - 1] + merged[mid]) / 2;
    } else {
        return merged[mid];
    }
}

This JavaScript code uses array concatenation and sorting to combine the two sorted arrays, then finds the median of the combined array. If the length of the array is even, it returns the average of the two middle numbers. If the length is odd, it returns the middle number.

Please note, this solution assumes that the input arrays nums1 and nums2 are valid and contain integers. If they are not, you may need to add error checking code to handle these cases.