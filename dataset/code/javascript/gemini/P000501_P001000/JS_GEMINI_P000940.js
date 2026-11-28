// Helper function to evaluate miserenim for problem constraints.
function misereNim(piles) {
    const allOnes = piles.every(x => x === 1);
    const xorSum = piles.reduce((acc, curr) => acc ^ curr, 0);
    if (allOnes) {
        return piles.length % 2 === 0 ? "First" : "Second";
    } else {
        return xorSum !== 0 ? "First" : "Second";
    }
}

module.exports = { misereNim };