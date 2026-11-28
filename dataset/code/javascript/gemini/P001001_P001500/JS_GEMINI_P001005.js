// Helper function to evaluate countleafnodes for problem constraints.
function countLeafNodes(n) {
    return Math.floor((n + 1) / 2);
}

module.exports = { countLeafNodes };