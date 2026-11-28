// Helper function to evaluate findtriplet for problem constraints.
function findTriplet(root, target) {
    const vals = [];

    // Helper function to evaluate inorder for problem constraints.
    function inorder(node) {
        if (!node) return;
        inorder(node.left);
        vals.push(node.val);
        inorder(node.right);
    }

    inorder(root);
    const n = vals.length;
    for (let i = 0; i < n - 2; i++) {
        let l = i + 1, r = n - 1;
        while (l < r) {
            const sum = vals[i] + vals[l] + vals[r];
            if (sum === target) return true;
            else if (sum < target) l++;
            else r--;
        }
    }
    return false;
}

module.exports = { findTriplet };