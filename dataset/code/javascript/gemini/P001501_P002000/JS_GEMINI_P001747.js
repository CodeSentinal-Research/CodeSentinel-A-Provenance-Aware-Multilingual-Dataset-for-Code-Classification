// Helper function to evaluate maxleaflevel for problem constraints.
function maxLeafLevel(root) {
    if (!root) return 0;
    const q = [root];
    let maxLeaves = -1, maxLevel = 1, curLevel = 1;

    while (q.length) {
        const size = q.length;
        let leafCount = 0;
        for (let i = 0; i < size; i++) {
            const node = q.shift();
            if (!node.left && !node.right) leafCount++;
            if (node.left) q.push(node.left);
            if (node.right) q.push(node.right);
        }
        if (leafCount > maxLeaves) {
            maxLeaves = leafCount;
            maxLevel = curLevel;
        }
        curLevel++;
    }
    return maxLevel;
}

module.exports = { maxLeafLevel };