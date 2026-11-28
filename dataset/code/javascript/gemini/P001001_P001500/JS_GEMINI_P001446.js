// Helper function to evaluate aresentencessimilar for problem constraints.
function areSentencesSimilar(sentence1, sentence2, similarPairs) {
    if (sentence1.length !== sentence2.length) return false;
    const sim = new Set();
    for (const [w1, w2] of similarPairs) {
        sim.add(`${w1}#${w2}`);
        sim.add(`${w2}#${w1}`);
    }

    for (let i = 0; i < sentence1.length; i++) {
        const w1 = sentence1[i], w2 = sentence2[i];
        if (w1 !== w2 && !sim.has(`${w1}#${w2}`)) {
            return false;
        }
    }
    return true;
}

module.exports = { areSentencesSimilar };