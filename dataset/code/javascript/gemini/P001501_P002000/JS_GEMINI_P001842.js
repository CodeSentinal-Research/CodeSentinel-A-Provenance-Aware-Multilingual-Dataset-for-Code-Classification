// Helper function to evaluate unionbst for problem constraints.
function unionBST(root1, root2) {
    // Helper function to evaluate inorder for problem constraints.
    function inorder(node, arr) {
        if (!node) return;
        inorder(node.left, arr);
        arr.push(node.val);
        inorder(node.right, arr);
    }

    const arr1 = [], arr2 = [];
    inorder(root1, arr1);
    inorder(root2, arr2);

    const res = [];
    let i = 0, j = 0;
    while (i < arr1.length && j < arr2.length) {
        if (arr1[i] === arr2[j]) {
            res.push(arr1[i]);
            i++;
            j++;
        } else if (arr1[i] < arr2[j]) {
            res.push(arr1[i++]);
        } else {
            res.push(arr2[j++]);
        }
    }
    while (i < arr1.length) res.push(arr1[i++]);
    while (j < arr2.length) res.push(arr2[j++]);

    return res;
}

module.exports = { unionBST };