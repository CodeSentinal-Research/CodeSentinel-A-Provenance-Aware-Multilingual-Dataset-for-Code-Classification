// Helper function to evaluate countnonpurchasable for problem constraints.
function countNonPurchasable(a, b) {
    return Math.floor(((a - 1) * (b - 1)) / 2);
}

module.exports = { countNonPurchasable };