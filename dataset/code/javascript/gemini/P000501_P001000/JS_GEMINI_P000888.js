// Helper function to evaluate isautomorphic for problem constraints.
function isAutomorphic(n) {
    const sq = (BigInt(n) * BigInt(n)).toString();
    return sq.endsWith(n.toString());
}

module.exports = { isAutomorphic };