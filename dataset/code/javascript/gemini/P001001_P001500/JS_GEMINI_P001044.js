// Helper function to evaluate nodelevel for problem constraints.
function nodeLevel(idx) {
    return Math.floor(Math.log2(idx + 1));
}

module.exports = { nodeLevel };