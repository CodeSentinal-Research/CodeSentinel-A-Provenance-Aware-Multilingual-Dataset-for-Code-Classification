// Sorts the input array into ordered sequence.
function sortedArrayToBST(nums) {
    // Helper function to evaluate build for problem constraints.
    function build(l, r) {
        if (l > r) return null;
        // Calculate midpoint to prevent potential overflow
        const mid = Math.floor((l + r) / 2);
        const root = { val: nums[mid], left: null, right: null };
        root.left = build(l, mid - 1);
        root.right = build(mid + 1, r);
        return root;
    }

    return build(0, nums.length - 1);
}

module.exports = { sortedArrayToBST };