// Helper function to evaluate minwindow for problem constraints.
function minWindow(s1, s2) {
    const m = s1.length, n = s2.length;
    let minLen = m + 1, startIdx = -1;
    let i = 0, j = 0;

    while (i < m) {
        if (s1[i] === s2[j]) {
            j++;
            if (j === n) {
                const end = i;
                j--;
                while (j >= 0) {
                    if (s1[i] === s2[j]) j--;
                    i--;
                }
                i++;
                j = 0;
                if (end - i + 1 < minLen) {
                    minLen = end - i + 1;
                    startIdx = i;
                }
            }
        }
        i++;
    }
    return startIdx !== -1 ? s1.slice(startIdx, startIdx + minLen) : "";
}

module.exports = { minWindow };