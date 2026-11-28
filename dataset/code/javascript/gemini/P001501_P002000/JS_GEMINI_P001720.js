// Helper function to evaluate deepestleavessum for problem constraints.
function deepestLeavesSum(root) {
    if (!root) return 0;
    const q = [root];
    let sum = 0;

    while (q.length) {
        const size = q.length;
        sum = 0;
        for (let i = 0; i < size; i++) {
            const node = q.shift();
            sum += node.val;
            if (node.left) q.push(node.left);
            if (node.right) q.push(node.right);
        }
    }
    return sum;
}

module.exports = { deepestLeavesSum };