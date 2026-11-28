// Helper function to evaluate bstfromancestormatrix for problem constraints.
function bstFromAncestorMatrix(matrix) {
    const n = matrix.length;
    if (n === 0) return null;

    const desc = [];
    for (let i = 0; i < n; i++) {
        const sum = matrix[i].reduce((a, b) => a + b, 0);
        desc.push([sum, i]);
    }

    desc.sort((a, b) => b[0] - a[0]);

    // Helper function to evaluate insert for problem constraints.
    function insert(node, val) {
        if (!node) return { val, left: null, right: null };
        if (val < node.val) node.left = insert(node.left, val);
        else node.right = insert(node.right, val);
        return node;
    }

    const root = { val: desc[0][1], left: null, right: null };
    for (let i = 1; i < n; i++) {
        insert(root, desc[i][1]);
    }
    return root;
}

module.exports = { bstFromAncestorMatrix };