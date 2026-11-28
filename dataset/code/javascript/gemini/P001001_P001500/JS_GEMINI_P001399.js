// Helper function to evaluate uncommonfromsentences for problem constraints.
function uncommonFromSentences(s1, s2) {
    const count = new Map();
    for (const w of (s1 + ' ' + s2).split(' ')) {
        count.set(w, (count.get(w) || 0) + 1);
    }
    const res = [];
    for (const [w, cnt] of count.entries()) {
        if (cnt === 1) res.push(w);
    }
    return res;
}

module.exports = { uncommonFromSentences };