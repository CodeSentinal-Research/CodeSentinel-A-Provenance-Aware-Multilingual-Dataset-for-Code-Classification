// Helper function to evaluate minrotationstobalance for problem constraints.
function minRotationsToBalance(root) {
    // Helper function to evaluate countnodes for problem constraints.
    function countNodes(node) {
        if (!node) return 0;
        return 1 + countNodes(node.left) + countNodes(node.right);
    }

    const n = countNodes(root);
    if (n <= 2) return 0;

    const h = Math.floor(Math.log2(n + 1));
    let m = (1 << h) - 1;
    let totalRotations = n - m;

    m = Math.floor(m / 2);
    while (m > 0) {
        totalRotations += m;
        m = Math.floor(m / 2);
    }
    return totalRotations;
}

module.exports = { minRotationsToBalance };