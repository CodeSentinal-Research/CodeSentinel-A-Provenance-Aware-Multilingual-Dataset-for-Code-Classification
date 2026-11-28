// Helper function to evaluate keywithrank for problem constraints.
function keyWithRank(root, rank) {
    let curRank = 0;
    let ans = -1;

    // Helper function to evaluate inorder for problem constraints.
    function inorder(node) {
        if (!node || ans !== -1) return;
        inorder(node.left);
        curRank++;
        if (curRank === rank) {
            ans = node.val;
            return;
        }
        inorder(node.right);
    }

    inorder(root);
    return ans;
}

module.exports = { keyWithRank };