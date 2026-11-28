// Helper function to evaluate leafnodes for problem constraints.
function leafNodes(arr) {
    const n = arr.length;
    return arr.slice(Math.floor(n / 2));
}

module.exports = { leafNodes };