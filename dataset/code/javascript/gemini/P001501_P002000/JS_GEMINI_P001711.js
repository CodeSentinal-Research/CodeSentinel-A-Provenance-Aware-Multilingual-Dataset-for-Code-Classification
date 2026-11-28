// Helper function to evaluate checkchildrensum for problem constraints.
function checkChildrenSum(root) {
    if (!root || (!root.left && !root.right)) return true;
    const childSum = (root.left ? root.left.val : 0) + (root.right ? root.right.val : 0);
    if (root.val !== childSum) return false;
    return checkChildrenSum(root.left) && checkChildrenSum(root.right);
}

module.exports = { checkChildrenSum };