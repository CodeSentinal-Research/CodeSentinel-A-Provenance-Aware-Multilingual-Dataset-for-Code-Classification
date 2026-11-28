function processTreeNode(node, isLeftChild) {
    if (!node) {
        return 0;
    }

    let leftChildPath = 0;
    let rightChildPath = 0;

    if (isLeftChild) {
        leftChildPath = processTreeNode(node.left, false) + 1;
    } else {
        rightChildPath = processTreeNode(node.right, true) + 1;
    }

    return Math.max(leftChildPath, rightChildPath);
}

function longestZigzagPath(root) {
    return Math.max(
        processTreeNode(root.left, true), 
        processTreeNode(root.right, false)
    );
}