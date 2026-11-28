// Helper function to evaluate countdistinctperlevel for problem constraints.
function countDistinctPerLevel(root) {
    if (!root) return [];
    const q = [root];
    const res = [];

    while (q.length) {
        const size = q.length;
        const distinct = new Set();
        for (let i = 0; i < size; i++) {
            const node = q.shift();
            distinct.add(node.val);
            if (node.left) q.push(node.left);
            if (node.right) q.push(node.right);
        }
        res.push(distinct.size);
    }
    return res;
}

module.exports = { countDistinctPerLevel };