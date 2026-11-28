// Helper function to evaluate areheapsidentical for problem constraints.
function areHeapsIdentical(a, b) {
    if (a.length !== b.length) return false;
    for (let i = 0; i < a.length; i++) {
        if (a[i] !== b[i]) return false;
    }
    return true;
}

module.exports = { areHeapsIdentical };