// Helper function to evaluate maxproduct for problem constraints.
function maxProduct(root) {
    const allSums = [];

    // Helper function to evaluate treesum for problem constraints.
    function treeSum(node) {
        if (!node) return 0n;
        const cur = BigInt(node.val) + treeSum(node.left) + treeSum(node.right);
        allSums.push(cur);
        return cur;
    }

    const total = treeSum(root);
    let maxProd = 0n;
    const MOD = 1000000007n;

    for (const s of allSums) {
        const prod = s * (total - s);
        if (prod > maxProd) maxProd = prod;
    }
    return Number(maxProd % MOD);
}

module.exports = { maxProduct };