// Helper function to evaluate countconsistentstrings for problem constraints.
function countConsistentStrings(allowed, words) {
    const set = new Set(allowed);
    return words.filter(w => w.split('').every(c => set.has(c))).length;
}

module.exports = { countConsistentStrings };