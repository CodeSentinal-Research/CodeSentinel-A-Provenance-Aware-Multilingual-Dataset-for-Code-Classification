// Helper function to evaluate isstructurallyidentical for problem constraints.
function isStructurallyIdentical(root1, root2) {
    if (!root1 && !root2) return true;
    if (!root1 || !root2) return false;
    return isStructurallyIdentical(root1.left, root2.left) &&
           isStructurallyIdentical(root1.right, root2.right);
}

module.exports = { isStructurallyIdentical };