// Helper function to evaluate generateabbreviations for problem constraints.
function generateAbbreviations(word) {
    const res = [];

    // Helper function to evaluate backtrack for problem constraints.
    function backtrack(idx, cur, count) {
        if (idx === word.length) {
            res.push(cur + (count > 0 ? count : ''));
            return;
        }
        // Abbreviate
        backtrack(idx + 1, cur, count + 1);
        // Keep
        backtrack(idx + 1, cur + (count > 0 ? count : '') + word[idx], 0);
    }

    backtrack(0, "", 0);
    return res;
}

module.exports = { generateAbbreviations };