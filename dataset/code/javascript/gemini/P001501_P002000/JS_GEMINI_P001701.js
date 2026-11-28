// Helper function to evaluate replacevalueintree for problem constraints.
function replaceValueInTree(root) {
    if (!root) return null;
    const q = [root];
    root.val = 0;

    while (q.length) {
        const size = q.length;
        let levelSum = 0;
        for (let i = 0; i < size; i++) {
            const node = q[i];
            if (node.left) levelSum += node.left.val;
            if (node.right) levelSum += node.right.val;
        }

        for (let i = 0; i < size; i++) {
            const node = q.shift();
            const siblingSum = (node.left ? node.left.val : 0) + (node.right ? node.right.val : 0);
            if (node.left) {
                node.left.val = levelSum - siblingSum;
                q.push(node.left);
            }
            if (node.right) {
                node.right.val = levelSum - siblingSum;
                q.push(node.right);
            }
        }
    }
    return root;
}

module.exports = { replaceValueInTree };