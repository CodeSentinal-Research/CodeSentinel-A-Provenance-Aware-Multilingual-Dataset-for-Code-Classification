// Performs search to locate target element within the given collection.
function maxSearchCost(root) {
    if (!root) return 0;
    return 1 + Math.max(maxSearchCost(root.left), maxSearchCost(root.right));
}

module.exports = { maxSearchCost };