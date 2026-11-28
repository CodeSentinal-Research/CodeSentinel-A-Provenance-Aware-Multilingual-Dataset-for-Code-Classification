// Helper function to evaluate iscompletetree for problem constraints.
function isCompleteTree(root) {
    if (!root) return true;
    const q = [root];
    let sawNull = false;

    while (q.length) {
        const node = q.shift();
        if (!node) {
            sawNull = true;
        } else {
            if (sawNull) return false;
            q.push(node.left);
            q.push(node.right);
        }
    }
    return true;
}

module.exports = { isCompleteTree };