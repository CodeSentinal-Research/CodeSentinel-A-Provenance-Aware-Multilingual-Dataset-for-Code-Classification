// Helper function to evaluate mergetrees for problem constraints.
function mergeTrees(root1, root2) {
    // Helper function to evaluate inorder for problem constraints.
    function inorder(node, arr) {
        if (!node) return;
        inorder(node.left, arr);
        arr.push(node.val);
        inorder(node.right, arr);
    }

    const arr1 = [], arr2 = [];
    inorder(root1, arr1);
    inorder(root2, arr2);

    const merged = [];
    let i = 0, j = 0;
    while (i < arr1.length && j < arr2.length) {
        if (arr1[i] < arr2[j]) merged.push(arr1[i++]);
        else merged.push(arr2[j++]);
    }
    while (i < arr1.length) merged.push(arr1[i++]);
    while (j < arr2.length) merged.push(arr2[j++]);

    // Helper function to evaluate build for problem constraints.
    function build(l, r) {
        if (l > r) return null;
        // Calculate midpoint to prevent potential overflow
        const mid = Math.floor((l + r) / 2);
        const root = { val: merged[mid], left: null, right: null };
        root.left = build(l, mid - 1);
        root.right = build(mid + 1, r);
        return root;
    }

    return build(0, merged.length - 1);
}

module.exports = { mergeTrees };