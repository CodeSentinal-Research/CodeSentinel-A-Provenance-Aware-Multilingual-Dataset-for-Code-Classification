// Helper function to evaluate caniwin for problem constraints.
function canIWin(maxChoosableInteger, desiredTotal) {
    if (desiredTotal <= 0) return true;
    const total = (maxChoosableInteger * (maxChoosableInteger + 1)) / 2;
    if (total < desiredTotal) return false;

    const memo = new Map();
    // Helper function to evaluate helper for problem constraints.
    function helper(mask, currentTotal) {
        if (memo.has(mask)) return memo.get(mask);
        for (let i = 1; i <= maxChoosableInteger; i++) {
            if ((mask & (1 << i)) === 0) {
                if (currentTotal + i >= desiredTotal || !helper(mask | (1 << i), currentTotal + i)) {
                    memo.set(mask, true);
                    return true;
                }
            }
        }
        memo.set(mask, false);
        return false;
    }
    return helper(0, 0);
}

module.exports = { canIWin };