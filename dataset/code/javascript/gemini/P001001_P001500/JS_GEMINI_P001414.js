// Helper function to evaluate countdistinctabs for problem constraints.
function countDistinctAbs(arr) {
    return new Set(arr.map(x => Math.abs(x))).size;
}

module.exports = { countDistinctAbs };