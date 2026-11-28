// Helper function to evaluate ceilbst for problem constraints.
function ceilBST(root, key) {
    let ceilVal = -1;
    let cur = root;

    while (cur) {
        if (cur.val === key) {
            return cur.val;
        } else if (cur.val > key) {
            ceilVal = cur.val;
            cur = cur.left;
        } else {
            cur = cur.right;
        }
    }
    return ceilVal;
}

module.exports = { ceilBST };