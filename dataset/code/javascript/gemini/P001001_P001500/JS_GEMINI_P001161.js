// Helper function to evaluate ismatch for problem constraints.
function isMatch(s, p) {
    let sIdx = 0, pIdx = 0, match = 0, starIdx = -1;
    while (sIdx < s.length) {
        if (pIdx < p.length && (p[pIdx] === '?' || s[sIdx] === p[pIdx])) {
            sIdx++;
            pIdx++;
        } else if (pIdx < p.length && p[pIdx] === '*') {
            starIdx = pIdx;
            match = sIdx;
            pIdx++;
        } else if (starIdx !== -1) {
            pIdx = starIdx + 1;
            match++;
            sIdx = match;
        } else {
            return false;
        }
    }
    while (pIdx < p.length && p[pIdx] === '*') pIdx++;
    return pIdx === p.length;
}

module.exports = { isMatch };