// Helper function to evaluate countvowelstrings for problem constraints.
function countVowelStrings(n) {
    return (n + 4) * (n + 3) * (n + 2) * (n + 1) / 24;
}

module.exports = { countVowelStrings };