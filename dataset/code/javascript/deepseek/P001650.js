Here is a JavaScript solution for the problem using the concept of tree traversal:

class TreeNode {
    constructor(val) {
        this.val = val;
        this.left = null;
        this.right = null;
    }
}

let inOrderIndex = {};

function constructFromInorderPostorder(inOrder, postOrder) {
    for (let i = 0; i < inOrder.length; i++) {
        inOrderIndex[inOrder[i]] = i;
    }
    return constructTree(inOrder, postOrder, 0, inOrder.length - 1);
}

function constructTree(inOrder, postOrder, start, end) {
    if (start > end) {
        return null;
    }
    let rootVal = postOrder.pop();
    let root = new TreeNode(rootVal);
    if (start == end) {
        return root;
    }
    let index = inOrderIndex[rootVal];
    root.right = constructTree(inOrder, postOrder, index + 1, end);
    root.left = constructTree(inOrder, postOrder, start, index - 1);
    return root;
}

In this code, we first create a helper class `TreeNode` to represent each node in the tree. We then use a map `inOrderIndex` to store the index of each element in the inorder traversal.

The `constructFromInorderPostorder` function constructs the tree by following these steps:

1. Parse the postorder array to get the last element (which is the root of the tree)
2. Recursively construct the left and right subtrees of the root from the inorder and postorder arrays
3. Return the root of the tree

The `constructTree` function is a helper function that constructs a tree by following these steps:

1. If the start index is larger than end index, return null (which indicates that we have traversed all nodes in the tree)
2. Parse the postorder array to get the last element (which is the root of the tree)
3. Recursively construct the left and right subtrees of the root from the inorder and postorder arrays
4. Return the root of the tree

Please note that you need to provide the inorder traversal and postorder traversal as input to the `constructFromInorderPostorder` function.

Also, the constraints in the problem statement (0 ≤ N ≤ 2 × 10^5) are not clear. The maximum size of the input data might vary depending on the specific use case. Please ensure that the input data is valid for your specific use case.