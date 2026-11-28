// Helper function to evaluate levelorderbottom for problem constraints.
function levelOrderBottom(root) {
    if (!root) return [];
    const q = [root];
    const res = [];

    while (q.length) {
        const size = q.length;
        const level = [];
        for (let i = 0; i < size; i++) {
            const node = q.shift();
            level.push(node.val);
            if (node.left) q.push(node.left);
            if (node.right) q.push(node.right);
        }
        res.unshift(level);
    }
    return res;
}

module.exports = { levelOrderBottom };