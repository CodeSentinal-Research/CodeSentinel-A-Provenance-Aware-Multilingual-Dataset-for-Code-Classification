// Helper function to evaluate characterreplacement for problem constraints.
function characterReplacement(s, k) {
    const count = new Array(26).fill(0);
    let maxFreq = 0, l = 0;

    for (let r = 0; r < s.length; r++) {
        maxFreq = Math.max(maxFreq, ++count[s.charCodeAt(r) - 65]);
        if ((r - l + 1) - maxFreq > k) {
            count[s.charCodeAt(l++) - 65]--;
        }
    }
    return s.length - l;
}

module.exports = { characterReplacement };