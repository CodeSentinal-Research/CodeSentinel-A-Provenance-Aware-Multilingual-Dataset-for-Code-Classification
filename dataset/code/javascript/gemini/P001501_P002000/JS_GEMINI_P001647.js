// Helper function to evaluate bottomview for problem constraints.
function bottomView(root) {
    if (!root) return [];
    const map = new Map();
    const q = [[root, 0]];

    while (q.length) {
        const [node, col] = q.shift();
        map.set(col, node.val);
        if (node.left) q.push([node.left, col - 1]);
        if (node.right) q.push([node.right, col + 1]);
    }

    const sortedCols = Array.from(map.keys()).sort((a, b) => a - b);
    return sortedCols.map(c => map.get(c));
}

module.exports = { bottomView };