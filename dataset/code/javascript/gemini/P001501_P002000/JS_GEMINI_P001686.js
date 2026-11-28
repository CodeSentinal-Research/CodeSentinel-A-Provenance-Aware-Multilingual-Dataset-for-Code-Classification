// Helper function to evaluate levelorderpredecessor for problem constraints.
function levelOrderPredecessor(root, targetVal) {
    if (!root) return -1;
    const q = [root];
    let prevVal = -1;

    while (q.length) {
        const node = q.shift();
        if (node.val === targetVal) return prevVal;
        prevVal = node.val;
        if (node.left) q.push(node.left);
        if (node.right) q.push(node.right);
    }
    return -1;
}

module.exports = { levelOrderPredecessor };