// Helper function to evaluate lcamultiplebst for problem constraints.
function lcaMultipleBST(root, nodes) {
    let minVal = Infinity, maxVal = -Infinity;
    for (const n of nodes) {
        if (n.val < minVal) minVal = n.val;
        if (n.val > maxVal) maxVal = n.val;
    }

    let cur = root;
    while (cur) {
        if (maxVal < cur.val) {
            cur = cur.left;
        } else if (minVal > cur.val) {
            cur = cur.right;
        } else {
            return cur;
        }
    }
    return null;
}

module.exports = { lcaMultipleBST };