// Helper function to evaluate maxscorewords for problem constraints.
function maxScoreWords(words, letters, score) {
    const count = new Array(26).fill(0);
    for (const c of letters) count[c.charCodeAt(0) - 97]++;

    // Helper function to evaluate backtrack for problem constraints.
    function backtrack(idx) {
        if (idx === words.length) return 0;
        let maxS = backtrack(idx + 1);

        const w = words[idx];
        const wCount = new Array(26).fill(0);
        let wScore = 0, canForm = true;

        for (const c of w) {
            const code = c.charCodeAt(0) - 97;
            wCount[code]++;
            wScore += score[code];
            if (wCount[code] > count[code]) canForm = false;
        }

        if (canForm) {
            for (let i = 0; i < 26; i++) count[i] -= wCount[i];
            maxS = Math.max(maxS, wScore + backtrack(idx + 1));
            for (let i = 0; i < 26; i++) count[i] += wCount[i];
        }
        return maxS;
    }

    return backtrack(0);
}

module.exports = { maxScoreWords };