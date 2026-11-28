// Helper function to evaluate minnodeslevel for problem constraints.
function minNodesLevel(root) {
    if (!root) return 0;
    const q = [root];
    let minNodes = Infinity, minLevel = 1, curLevel = 1;

    while (q.length) {
        const size = q.length;
        if (size < minNodes) {
            minNodes = size;
            minLevel = curLevel;
        }
        for (let i = 0; i < size; i++) {
            const node = q.shift();
            if (node.left) q.push(node.left);
            if (node.right) q.push(node.right);
        }
        curLevel++;
    }
    return minLevel;
}

module.exports = { minNodesLevel };