// Helper function to evaluate getsum for problem constraints.
function getSum(a, b) {
    while (b !== 0) {
        const carry = (a & b) << 1;
        a = a ^ b;
        b = carry;
    }
    return a;
}

module.exports = { getSum };