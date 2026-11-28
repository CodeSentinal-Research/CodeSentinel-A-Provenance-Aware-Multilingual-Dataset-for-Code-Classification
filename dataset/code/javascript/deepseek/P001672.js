let nodes = [], index = 0;

function MorrisPreorderTraversal(root) {
    if(root !== null) {
        nodes.push({val: root.val, left: root.left, right: root.right});
        MorrisPreorderTraversal(root.left);
        MorrisPreorderTraversal(root.right);
    } else {
        nodes.push(null);
    }
}