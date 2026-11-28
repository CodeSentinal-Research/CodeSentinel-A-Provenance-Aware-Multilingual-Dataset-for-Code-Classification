Here is a simple solution using JavaScript. This solution assumes that the tree is represented as an array where the first element is the root, and each element represents a child of its parent in the tree.

function checkTree(tree) {
    for (let i = 1; i < tree.length; i++) {
        if (tree[i] == null) {
            return "NO";
        }
    }
    return "YES";
}

This function starts by checking if the root is null. If it is, it means the tree is empty and we return "NO". Otherwise, it iterates over each element in the array, except for the first one (which is the root). If it encounters a null element, it means that this is not a child of its parent, so we return "NO". If it doesn't find any null elements, it means all the internal nodes have exactly two children, so we return "YES".

This solution assumes that the input tree is well-formed (i.e., each internal node has exactly two children), and that there are no cycles in the tree.

Please note that this is a simple solution and may not work correctly if there are multiple cycles in the tree, or if the tree is not binary. In such cases, you would need a more complex algorithm to handle these cases.