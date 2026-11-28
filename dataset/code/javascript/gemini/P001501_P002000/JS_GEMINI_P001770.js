// Helper function to evaluate replacewithlevelsum for problem constraints.
function replaceWithLevelSum(root) {
    if (!root) return null;
    const q = [root];

    while (q.length) {
        const size = q.length;
        const list = [];
        let levelSum = 0;
        for (let i = 0; i < size; i++) {
            const node = q.shift();
            list.push(node);
            levelSum += node.val;
            if (node.left) q.push(node.left);
            if (node.right) q.push(node.right);
        }
        for (const node of list) {
            node.val = levelSum;
        }
    }
    return root;
}

module.exports = { replaceWithLevelSum };