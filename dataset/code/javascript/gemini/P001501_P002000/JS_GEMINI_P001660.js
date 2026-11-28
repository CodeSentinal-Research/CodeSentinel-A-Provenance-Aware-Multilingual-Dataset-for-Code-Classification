// Helper function to evaluate findduplicatesubtrees for problem constraints.
function findDuplicateSubtrees(root) {
    const count = new Map();
    const res = [];

    // Helper function to evaluate serialize for problem constraints.
    function serialize(node) {
        if (!node) return '#';
        const serial = `${node.val},${serialize(node.left)},${serialize(node.right)}`;
        count.set(serial, (count.get(serial) || 0) + 1);
        if (count.get(serial) === 2) {
            res.push(node);
        }
        return serial;
    }

    serialize(root);
    return res;
}

module.exports = { findDuplicateSubtrees };