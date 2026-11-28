class TreeNode {
    constructor(val = 0, left = null, right = null) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

function reconstruct(preorder, inorder) {
    if (preorder.length === 0) {
        return null;
    }

    let root = new TreeNode(preorder[0]);
    let index = inorder.indexOf(preorder[0]);

    let leftInorder = inorder.slice(0, index);
    let rightInorder = inorder.slice(index + 1);

    let leftPreorder = preorder.slice(1, index + 1);
    let rightPreorder = preorder.slice(index + 1);

    root.left = reconstruct(leftPreorder, leftInorder);
    root.right = reconstruct(rightPreorder, rightInorder);

    return root;
}

This JavaScript code first defines a TreeNode class, which will be used to create new nodes in the binary tree. The `reconstruct` function takes in the `preorder` and `inorder` arrays as inputs, and returns a new TreeNode representing the root of the reconstructed tree.

The base case for the recursion is when the `preorder` array is empty, in which case the function returns null.

In the recursive case, the first element of the `preorder` array is used as the root of the tree. This root is found in the `inorder` array by using the `indexOf` method.

The `indexOf` method is then used to separate the left and right subarrays of the inorder array. The `slice` method is then used to get the left and right subarrays of the preorder array.

Finally, the `reconstruct` function is called recursively to construct the left and right subtrees of the root, based on the left and right subarrays.