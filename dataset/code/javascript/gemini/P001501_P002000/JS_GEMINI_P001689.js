// Helper function to evaluate mincameracover for problem constraints.
function minCameraCover(root) {
    let cameras = 0;

    // Helper function to evaluate dfs for problem constraints.
    function dfs(node) {
        if (!node) return 2;
        const l = dfs(node.left);
        const r = dfs(node.right);

        if (l === 0 || r === 0) {
            cameras++;
            return 1;
        }
        if (l === 1 || r === 1) return 2;
        return 0;
    }

    if (dfs(root) === 0) cameras++;
    return cameras;
}

module.exports = { minCameraCover };