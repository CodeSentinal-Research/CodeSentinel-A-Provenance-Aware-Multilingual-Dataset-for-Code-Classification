// Helper function to evaluate floorbst for problem constraints.
function floorBST(root, key) {
    let floorVal = -1;
    let cur = root;

    while (cur) {
        if (cur.val === key) {
            return cur.val;
        } else if (cur.val < key) {
            floorVal = cur.val;
            cur = cur.right;
        } else {
            cur = cur.left;
        }
    }
    return floorVal;
}

module.exports = { floorBST };