function verifyBST(sequence) {
    if (sequence.length < 2) {
        return 'YES';
    }

    let root = sequence[0];
    let leftSubtree = [];
    let rightSubtree = [];

    for (let i = 1; i < sequence.length; i++) {
        if (sequence[i] < root) {
            leftSubtree.push(sequence[i]);
        } else {
            rightSubtree.push(sequence[i]);
        }
    }

    if (leftSubtree.length > 0 && rightSubtree.length > 0) {
        return 'NO';
    }

    if (leftSubtree.length > 0) {
        return verifyBST(leftSubtree);
    }

    if (rightSubtree.length > 0) {
        return verifyBST(rightSubtree);
    }

    return 'YES';
}
This JavaScript function works by iterating over the given sequence and maintaining two arrays: leftSubtree and rightSubtree. For each element in the sequence, if it is smaller than the root, it is added to the leftSubtree array, otherwise it is added to the rightSubtree array.

Once all elements have been processed, if the leftSubtree and rightSubtree arrays are not empty, it means the sequence can't represent a BST, so it returns 'NO'. Otherwise, it recursively calls the verifyBST function on leftSubtree and rightSubtree until it has processed all elements, then it returns 'YES'.

This solution assumes that the input sequence is a preorder traversal of a Binary Search Tree, which means it starts with a root node, followed by a series of smaller values in the left subtree, and then a larger series in the right subtree.