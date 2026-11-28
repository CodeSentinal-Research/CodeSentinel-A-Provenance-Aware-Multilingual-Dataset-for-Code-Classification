// Helper function to evaluate minswapsbracketbalance for problem constraints.
function minSwapsBracketBalance(s) {
    let unbalanced = 0;
    for (const c of s) {
        if (c === '[') {
            if (unbalanced > 0) unbalanced--;
        } else {
            unbalanced++;
        }
    }
    return Math.floor((unbalanced + 1) / 2);
}

module.exports = { minSwapsBracketBalance };