Here is the JavaScript code to reconstruct the binary tree from depth-encoded preorder traversal.

function solve(encoded) {
    let indexMap = new Map();
    let index = 0;

    function buildTree(lower, upper) {
        if (lower > upper) return null;

        let rootVal = encoded[index++];
        let root = new TreeNode(rootVal);

        root.left = buildTree(lower, rootVal - 1);
        root.right = buildTree(rootVal + 1, upper);

        return root;
    }

    let n = encoded.length;
    indexMap.set(0, buildTree(0, encoded[0] - 1));

    for (let i = 1; i < n; i++) {
        if (encoded[i] - 1 > indexMap.get(i - 1).val) {
            indexMap.set(i, buildTree(indexMap.get(i - 1).val + 1, encoded[i] - 1));
        }
        else {
            indexMap.set(i, buildTree(indexMap.get(i - 1).val + 1, indexMap.get(i - 1).val));
        }
    }

    return indexMap.get(n - 1);
}

This function uses a map to remember the node values at each level of the tree, and it recursively constructs the tree from these remembered values.

In the recursive function `buildTree(lower, upper)`, it constructs a tree node with value between `lower` and `upper`. It also updates the index into the traversal array.

In the main function, it iterates through the traversal array and for each element, it computes the maximum value `x` for which `x-1` is less than or equal to `encoded[i]`, and calls the recursive function `buildTree(lower, x-1)` to construct the left child of the node. Then, it constructs the right child by calling the recursive function with `x+1` as the lower and upper value.

The last line in the main function returns the root of the constructed tree.