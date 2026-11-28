// Helper function to evaluate modadd for problem constraints.
function modAdd(a, b, m) {
    return ((a % m) + (b % m)) % m;
}

module.exports = { modAdd };