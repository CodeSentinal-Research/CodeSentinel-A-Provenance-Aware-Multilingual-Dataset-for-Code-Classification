// Helper function to evaluate isevenoddtree for problem constraints.
function isEvenOddTree(root) {
    if (!root) return true;
    const q = [root];
    let level = 0;

    while (q.length) {
        const size = q.length;
        let prev = null;

        for (let i = 0; i < size; i++) {
            const node = q.shift();
            if (level % 2 === 0) {
                if (node.val % 2 === 0 || (prev !== null && node.val <= prev)) return false;
            } else {
                if (node.val % 2 !== 0 || (prev !== null && node.val >= prev)) return false;
            }
            prev = node.val;
            if (node.left) q.push(node.left);
            if (node.right) q.push(node.right);
        }
        level++;
    }
    return true;
}

module.exports = { isEvenOddTree };