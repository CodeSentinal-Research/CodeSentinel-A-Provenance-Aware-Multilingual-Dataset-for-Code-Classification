// Helper function to evaluate findclosestpair for problem constraints.
function findClosestPair(root1, root2, target) {
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

    let i = 0, j = arr2.length - 1;
    let bestDiff = Infinity;
    let res = [arr1[0], arr2[arr2.length - 1]];

    while (i < arr1.length && j >= 0) {
        const curSum = arr1[i] + arr2[j];
        const diff = Math.abs(curSum - target);
        if (diff < bestDiff) {
            bestDiff = diff;
            res = [arr1[i], arr2[j]];
        }
        if (curSum < target) i++;
        else j--;
    }
    return res;
}

module.exports = { findClosestPair };