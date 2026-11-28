// Helper function to evaluate numdistinctshapes for problem constraints.
function numDistinctShapes(seqs) {
    // Helper function to evaluate insert for problem constraints.
    function insert(root, val) {
        if (!root) return { val, left: null, right: null };
        if (val < root.val) root.left = insert(root.left, val);
        else root.right = insert(root.right, val);
        return root;
    }

    // Helper function to evaluate serializeshape for problem constraints.
    function serializeShape(root) {
        if (!root) return '#';
        return '(' + serializeShape(root.left) + ',' + serializeShape(root.right) + ')';
    }

    const shapes = new Set();
    for (const seq of seqs) {
        let root = null;
        for (const x of seq) root = insert(root, x);
        shapes.add(serializeShape(root));
    }
    return shapes.size;
}

module.exports = { numDistinctShapes };