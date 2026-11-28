// Helper function to evaluate modsub for problem constraints.
function modSub(a, b, m) {
    return ((a % m) - (b % m) + m) % m;
}

module.exports = { modSub };