// Helper function to evaluate countpairs for problem constraints.
function countPairs(root1, root2, target) {
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
    let count = 0;

    while (i < arr1.length && j >= 0) {
        const curSum = arr1[i] + arr2[j];
        if (curSum === target) {
            count++;
            i++;
            j--;
        } else if (curSum < target) {
            i++;
        } else {
            j--;
        }
    }
    return count;
}

module.exports = { countPairs };