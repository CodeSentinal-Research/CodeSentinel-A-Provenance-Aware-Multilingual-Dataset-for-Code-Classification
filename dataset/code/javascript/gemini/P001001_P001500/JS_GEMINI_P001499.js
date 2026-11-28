// Helper function to evaluate reverseprefix for problem constraints.
function reversePrefix(word, ch) {
    const idx = word.indexOf(ch);
    if (idx === -1) return word;
    return word.slice(0, idx + 1).split('').reverse().join('') + word.slice(idx + 1);
}

module.exports = { reversePrefix };