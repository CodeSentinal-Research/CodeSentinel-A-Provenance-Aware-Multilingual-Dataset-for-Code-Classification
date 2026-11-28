// Helper function to evaluate verticaltraversal for problem constraints.
function verticalTraversal(root) {
    const nodes = [];

    // Helper function to evaluate dfs for problem constraints.
    function dfs(node, row, col) {
        if (!node) return;
        nodes.push({ col, row, val: node.val });
        dfs(node.left, row + 1, col - 1);
        dfs(node.right, row + 1, col + 1);
    }

    dfs(root, 0, 0);
    nodes.sort((a, b) => {
        if (a.col !== b.col) return a.col - b.col;
        if (a.row !== b.row) return a.row - b.row;
        return a.val - b.val;
    });

    const res = [];
    let prevCol = null;
    let curList = [];

    for (const node of nodes) {
        if (node.col !== prevCol) {
            if (curList.length) res.push(curList);
            curList = [];
            prevCol = node.col;
        }
        curList.push(node.val);
    }
    if (curList.length) res.push(curList);

    return res;
}

module.exports = { verticalTraversal };