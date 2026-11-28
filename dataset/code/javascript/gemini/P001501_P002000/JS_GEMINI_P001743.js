// Helper function to evaluate firstnonfullnode for problem constraints.
function firstNonFullNode(root) {
    if (!root) return -1;
    const q = [root];

    while (q.length) {
        const node = q.shift();
        if (!node.left || !node.right) return node.val;
        q.push(node.left);
        q.push(node.right);
    }
    return -1;
}

module.exports = { firstNonFullNode };