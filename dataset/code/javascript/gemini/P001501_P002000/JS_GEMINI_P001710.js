// Helper function to evaluate copyrandombinarytree for problem constraints.
function copyRandomBinaryTree(root) {
    if (!root) return null;
    const cloned = new Map();

    // Helper function to evaluate clonestructure for problem constraints.
    function cloneStructure(node) {
        if (!node) return null;
        const copy = { val: node.val, left: null, right: null, random: null };
        cloned.set(node, copy);
        copy.left = cloneStructure(node.left);
        copy.right = cloneStructure(node.right);
        return copy;
    }

    const newRoot = cloneStructure(root);

    // Helper function to evaluate connectrandom for problem constraints.
    function connectRandom(node) {
        if (!node) return;
        if (node.random) {
            cloned.get(node).random = cloned.get(node.random);
        }
        connectRandom(node.left);
        connectRandom(node.right);
    }

    connectRandom(root);
    return newRoot;
}

module.exports = { copyRandomBinaryTree };