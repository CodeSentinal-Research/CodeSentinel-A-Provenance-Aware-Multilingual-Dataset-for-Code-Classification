// Helper function to evaluate countdivisibleinrange for problem constraints.
function countDivisibleInRange(l, r, k) {
    return Math.floor(r / k) - Math.floor((l - 1) / k);
}

module.exports = { countDivisibleInRange };