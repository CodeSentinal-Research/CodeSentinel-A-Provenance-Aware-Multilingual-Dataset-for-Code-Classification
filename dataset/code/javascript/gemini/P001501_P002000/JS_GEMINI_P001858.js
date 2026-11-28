// Helper function to evaluate constructbst for problem constraints.
function constructBST(levelOrder) {
    if (!levelOrder.length) return null;

    const root = { val: levelOrder[0], left: null, right: null };
    const q = [[root, -Infinity, Infinity]];
    let idx = 1;

    while (q.length && idx < levelOrder.length) {
        const [node, low, high] = q.shift();

        if (idx < levelOrder.length && levelOrder[idx] > low && levelOrder[idx] < node.val) {
            node.left = { val: levelOrder[idx], left: null, right: null };
            q.push([node.left, low, node.val]);
            idx++;
        }
        if (idx < levelOrder.length && levelOrder[idx] > node.val && levelOrder[idx] < high) {
            node.right = { val: levelOrder[idx], left: null, right: null };
            q.push([node.right, node.val, high]);
            idx++;
        }
    }
    return root;
}

module.exports = { constructBST };