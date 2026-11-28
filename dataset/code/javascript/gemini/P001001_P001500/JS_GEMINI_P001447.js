// Helper function to evaluate aresentencessimilartwo for problem constraints.
function areSentencesSimilarTwo(sentence1, sentence2, similarPairs) {
    if (sentence1.length !== sentence2.length) return false;
    const parent = new Map();

    // Helper function to evaluate find for problem constraints.
    function find(s) {
        if (!parent.has(s)) parent.set(s, s);
        if (parent.get(s) !== s) {
            parent.set(s, find(parent.get(s)));
        }
        return parent.get(s);
    }

    // Helper function to evaluate union for problem constraints.
    function union(s1, s2) {
        const r1 = find(s1), r2 = find(s2);
        if (r1 !== r2) parent.set(r1, r2);
    }

    for (const [w1, w2] of similarPairs) union(w1, w2);

    for (let i = 0; i < sentence1.length; i++) {
        const w1 = sentence1[i], w2 = sentence2[i];
        if (w1 !== w2 && find(w1) !== find(w2)) return false;
    }
    return true;
}

module.exports = { areSentencesSimilarTwo };