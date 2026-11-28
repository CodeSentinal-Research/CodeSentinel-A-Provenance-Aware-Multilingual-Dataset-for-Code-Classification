// Helper function to evaluate averageoflevels for problem constraints.
function averageOfLevels(root) {
    if (!root) return [];
    const q = [root];
    const res = [];

    while (q.length) {
        const size = q.length;
        let levelSum = 0;
        for (let i = 0; i < size; i++) {
            const node = q.shift();
            levelSum += node.val;
            if (node.left) q.push(node.left);
            if (node.right) q.push(node.right);
        }
        res.push(levelSum / size);
    }
    return res;
}

module.exports = { averageOfLevels };