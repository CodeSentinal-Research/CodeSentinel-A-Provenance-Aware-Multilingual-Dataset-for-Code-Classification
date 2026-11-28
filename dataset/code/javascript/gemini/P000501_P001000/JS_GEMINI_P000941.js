// Helper function to evaluate nimwinner for problem constraints.
function nimWinner(piles) {
    const xorSum = piles.reduce((acc, curr) => acc ^ curr, 0);
    return xorSum !== 0 ? "First" : "Second";
}

module.exports = { nimWinner };