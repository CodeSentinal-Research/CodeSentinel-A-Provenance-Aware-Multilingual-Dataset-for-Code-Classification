// Helper function to evaluate maxadjacentleveldiff for problem constraints.
function maxAdjacentLevelDiff(root) {
    if (!root) return 0;
    const q = [root];
    const levelSums = [];

    while (q.length) {
        const size = q.length;
        let curSum = 0;
        for (let i = 0; i < size; i++) {
            const node = q.shift();
            curSum += node.val;
            if (node.left) q.push(node.left);
            if (node.right) q.push(node.right);
        }
        levelSums.push(curSum);
    }

    let maxDiff = 0;
    for (let i = 1; i < levelSums.length; i++) {
        const diff = Math.abs(levelSums[i] - levelSums[i - 1]);
        if (diff > maxDiff) maxDiff = diff;
    }
    return maxDiff;
}

module.exports = { maxAdjacentLevelDiff };