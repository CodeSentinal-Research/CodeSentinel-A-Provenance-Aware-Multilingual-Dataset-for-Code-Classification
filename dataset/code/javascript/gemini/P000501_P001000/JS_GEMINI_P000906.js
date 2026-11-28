// Helper function to evaluate modmul for problem constraints.
function modMul(a, b, m) {
    return ((a % m) * (b % m)) % m;
}

module.exports = { modMul };