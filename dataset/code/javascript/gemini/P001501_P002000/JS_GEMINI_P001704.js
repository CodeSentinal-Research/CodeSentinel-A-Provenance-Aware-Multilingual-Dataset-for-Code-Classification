// Helper function to evaluate isisomorphic for problem constraints.
function isIsomorphic(root1, root2) {
    if (!root1 && !root2) return true;
    if (!root1 || !root2 || root1.val !== root2.val) return false;
    return (isIsomorphic(root1.left, root2.left) && isIsomorphic(root1.right, root2.right)) ||
           (isIsomorphic(root1.left, root2.right) && isIsomorphic(root1.right, root2.left));
}

module.exports = { isIsomorphic };