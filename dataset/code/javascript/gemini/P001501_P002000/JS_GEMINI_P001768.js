// Helper function to evaluate largestvalues for problem constraints.
function largestValues(root) {
    if (!root) return [];
    const q = [root];
    const res = [];

    while (q.length) {
        const size = q.length;
        let maxVal = -Infinity;
        for (let i = 0; i < size; i++) {
            const node = q.shift();
            if (node.val > maxVal) maxVal = node.val;
            if (node.left) q.push(node.left);
            if (node.right) q.push(node.right);
        }
        res.push(maxVal);
    }
    return res;
}

module.exports = { largestValues };