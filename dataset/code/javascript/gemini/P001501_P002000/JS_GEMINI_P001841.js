// Helper function to evaluate intersectionbst for problem constraints.
function intersectionBST(root1, root2) {
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
            i++;
        } else {
            j++;
        }
    }
    return res;
}

module.exports = { intersectionBST };