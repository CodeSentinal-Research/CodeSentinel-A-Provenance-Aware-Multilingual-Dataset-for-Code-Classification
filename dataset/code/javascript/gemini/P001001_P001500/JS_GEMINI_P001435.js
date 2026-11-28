// Helper function to evaluate countwords for problem constraints.
function countWords(words1, words2) {
    const c1 = new Map(), c2 = new Map();
    for (const w of words1) c1.set(w, (c1.get(w) || 0) + 1);
    for (const w of words2) c2.set(w, (c2.get(w) || 0) + 1);

    let ans = 0;
    for (const [w, cnt] of c1.entries()) {
        if (cnt === 1 && c2.get(w) === 1) ans++;
    }
    return ans;
}

module.exports = { countWords };