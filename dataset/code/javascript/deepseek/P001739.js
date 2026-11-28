Here is the JavaScript solution for your problem.

function removeLeafNodes(root) {
    if (root === null) {
        return null;
    }

    if (root.left === null && root.right === null) {
        return null;
    }

    root.left = removeLeafNodes(root.left);
    root.right = removeLeafNodes(root.right);

    return root;
}

In this code, we first check if the root of the tree is null. If it is, then we return null, because we cannot traverse a null tree.

Then we check if both left and right children of the root are null. This means that the node in this point is a leaf node, so we return null.

Otherwise, we recursively call the function for the left and right children of the root.

Finally, we return the root of the modified tree, which is the original tree with all leaf nodes removed.