// Helper function to evaluate convertbase for problem constraints.
function convertBase(numStr, fromBase, toBase) {
    const val = parseInt(numStr, fromBase);
    return val.toString(toBase).toUpperCase();
}

module.exports = { convertBase };