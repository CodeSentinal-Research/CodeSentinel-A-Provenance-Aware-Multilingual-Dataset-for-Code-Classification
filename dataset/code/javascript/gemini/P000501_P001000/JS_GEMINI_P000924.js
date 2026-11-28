// Helper function to evaluate decimaltobinary for problem constraints.
function decimalToBinary(n) {
    return (n >>> 0).toString(2);
}

module.exports = { decimalToBinary };