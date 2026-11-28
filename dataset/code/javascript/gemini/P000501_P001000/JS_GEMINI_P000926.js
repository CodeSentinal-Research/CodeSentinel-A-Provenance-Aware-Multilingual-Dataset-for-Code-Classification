// Helper function to evaluate convertbases for problem constraints.
function convertBases(n) {
    return [n.toString(8), n.toString(16).toUpperCase()];
}

module.exports = { convertBases };