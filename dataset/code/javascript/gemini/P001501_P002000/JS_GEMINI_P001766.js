// Helper function to evaluate findlevelmedians for problem constraints.
function findLevelMedians(root) {
    if (!root) return [];
    const q = [root];
    const medians = [];

    while (q.length) {
        const size = q.length;
        const vals = [];
        for (let i = 0; i < size; i++) {
            const node = q.shift();
            vals.push(node.val);
            if (node.left) q.push(node.left);
            if (node.right) q.push(node.right);
        }
        vals.sort((a, b) => a - b);
        if (size % 2 === 1) {
            medians.push(vals[Math.floor(size / 2)]);
        } else {
            medians.push((vals[size / 2 - 1] + vals[size / 2]) / 2);
        }
    }
    return medians;
}

module.exports = { findLevelMedians };