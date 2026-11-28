// Helper function to evaluate frobeniusnumber for problem constraints.
function frobeniusNumber(a, b) {
    return a * b - a - b;
}

module.exports = { frobeniusNumber };