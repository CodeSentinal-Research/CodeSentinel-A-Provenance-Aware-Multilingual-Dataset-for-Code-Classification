// Helper function to evaluate levelordersuccessor for problem constraints.
function levelOrderSuccessor(root, targetVal) {
    if (!root) return -1;
    const q = [root];
    let found = false;

    while (q.length) {
        const node = q.shift();
        if (found) return node.val;
        if (node.val === targetVal) found = true;
        if (node.left) q.push(node.left);
        if (node.right) q.push(node.right);
    }
    return -1;
}

module.exports = { levelOrderSuccessor };