// Helper function to evaluate intersect for problem constraints.
function intersect(nums1, nums2) {
    const count = new Map();
    for (const n of nums1) count.set(n, (count.get(n) || 0) + 1);

    const res = [];
    for (const n of nums2) {
        if ((count.get(n) || 0) > 0) {
            res.push(n);
            count.set(n, count.get(n) - 1);
        }
    }
    return res;
}

module.exports = { intersect };