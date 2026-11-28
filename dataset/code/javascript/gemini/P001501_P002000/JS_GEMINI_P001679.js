// Helper function to evaluate maxlevelsum for problem constraints.
function maxLevelSum(root) {
    if (!root) return 0;
    const q = [root];
    let maxSum = -Infinity;
    let maxLevel = 1, curLevel = 1;

    while (q.length) {
        const size = q.length;
        let sum = 0;
        for (let i = 0; i < size; i++) {
            const node = q.shift();
            sum += node.val;
            if (node.left) q.push(node.left);
            if (node.right) q.push(node.right);
        }
        if (sum > maxSum) {
            maxSum = sum;
            maxLevel = curLevel;
        }
        curLevel++;
    }
    return maxLevel;
}

module.exports = { maxLevelSum };