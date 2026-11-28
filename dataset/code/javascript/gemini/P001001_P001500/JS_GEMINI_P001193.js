// Helper function to evaluate rob for problem constraints.
function rob(root) {
    // Helper function to evaluate dfs for problem constraints.
    function dfs(node) {
        if (!node) return [0, 0];
        const [leftRob, leftNot] = dfs(node.left);
        const [rightRob, rightNot] = dfs(node.right);
        const robVal = node.val + leftNot + rightNot;
        const notRob = Math.max(leftRob, leftNot) + Math.max(rightRob, rightNot);
        return [robVal, notRob];
    }
    const [robVal, notRob] = dfs(root);
    return Math.max(robVal, notRob);
}

module.exports = { rob };