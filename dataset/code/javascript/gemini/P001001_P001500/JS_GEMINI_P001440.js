// Helper function to evaluate findlongestword for problem constraints.
function findLongestWord(s, dictionary) {
    // Helper function to evaluate issubseq for problem constraints.
    function isSubseq(w) {
        let i = 0, j = 0;
        while (i < s.length && j < w.length) {
            if (s[i] === w[j]) j++;
            i++;
        }
        return j === w.length;
    }

    let best = "";
    for (const w of dictionary) {
        if (isSubseq(w)) {
            if (w.length > best.length || (w.length === best.length && w < best)) {
                best = w;
            }
        }
    }
    return best;
}

module.exports = { findLongestWord };