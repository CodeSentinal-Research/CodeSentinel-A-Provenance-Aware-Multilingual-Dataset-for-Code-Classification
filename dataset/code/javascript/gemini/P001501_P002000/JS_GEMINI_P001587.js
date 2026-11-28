// Helper function to evaluate numberofsubstrings for problem constraints.
function numberOfSubstrings(s) {
    const last = [-1, -1, -1];
    let ans = 0;

    for (let i = 0; i < s.length; i++) {
        last[s.charCodeAt(i) - 97] = i;
        ans += 1 + Math.min(...last);
    }
    return ans;
}

module.exports = { numberOfSubstrings };