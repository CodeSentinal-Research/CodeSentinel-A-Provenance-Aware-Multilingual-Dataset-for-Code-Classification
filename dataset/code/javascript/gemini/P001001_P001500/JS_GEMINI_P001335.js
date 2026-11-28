// Helper function to evaluate makesquare for problem constraints.
function makesquare(matchsticks) {
    const total = matchsticks.reduce((a, b) => a + b, 0);
    if (total % 4 !== 0) return false;
    const side = total / 4;

    matchsticks.sort((a, b) => b - a);
    if (matchsticks[0] > side) return false;

    const sides = [0, 0, 0, 0];

    // Helper function to evaluate backtrack for problem constraints.
    function backtrack(idx) {
        if (idx === matchsticks.length) return true;
        for (let i = 0; i < 4; i++) {
            if (sides[i] + matchsticks[idx] <= side) {
                sides[i] += matchsticks[idx];
                if (backtrack(idx + 1)) return true;
                sides[i] -= matchsticks[idx];
            }
            if (sides[i] === 0) break;
        }
        return false;
    }

    return backtrack(0);
}

module.exports = { makesquare };