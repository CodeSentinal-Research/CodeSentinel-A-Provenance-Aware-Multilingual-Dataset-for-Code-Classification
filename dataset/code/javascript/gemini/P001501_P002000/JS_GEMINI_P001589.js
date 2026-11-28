// Helper function to evaluate longestwpi for problem constraints.
function longestWPI(hours) {
    let score = 0, ans = 0;
    const seen = new Map();

    for (let i = 0; i < hours.length; i++) {
        score += hours[i] > 8 ? 1 : -1;
        if (score > 0) {
            ans = i + 1;
        } else {
            if (!seen.has(score)) seen.set(score, i);
            if (seen.has(score - 1)) {
                ans = Math.max(ans, i - seen.get(score - 1));
            }
        }
    }
    return ans;
}

module.exports = { longestWPI };