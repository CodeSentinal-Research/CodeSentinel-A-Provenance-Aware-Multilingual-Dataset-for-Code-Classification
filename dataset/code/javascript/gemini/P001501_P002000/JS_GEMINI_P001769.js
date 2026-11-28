// Helper function to evaluate smallestvalues for problem constraints.
function smallestValues(root) {
    if (!root) return [];
    const q = [root];
    const res = [];

    while (q.length) {
        const size = q.length;
        let minVal = Infinity;
        for (let i = 0; i < size; i++) {
            const node = q.shift();
            if (node.val < minVal) minVal = node.val;
            if (node.left) q.push(node.left);
            if (node.right) q.push(node.right);
        }
        res.push(minVal);
    }
    return res;
}

module.exports = { smallestValues };