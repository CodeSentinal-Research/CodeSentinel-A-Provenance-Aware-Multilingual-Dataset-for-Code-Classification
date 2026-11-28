// Performs search to locate target element within the given collection.
function searchBST(root, val) {
    let cur = root;
    while (cur && cur.val !== val) {
        cur = val < cur.val ? cur.left : cur.right;
    }
    return cur;
}

module.exports = { searchBST };