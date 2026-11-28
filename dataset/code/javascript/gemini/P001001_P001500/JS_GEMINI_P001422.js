// Helper function to evaluate findwords for problem constraints.
function findWords(words) {
    const row1 = new Set('qwertyuiop');
    const row2 = new Set('asdfghjkl');
    const row3 = new Set('zxcvbnm');

    return words.filter(w => {
        const letters = w.toLowerCase().split('');
        return letters.every(c => row1.has(c)) ||
               letters.every(c => row2.has(c)) ||
               letters.every(c => row3.has(c));
    });
}

module.exports = { findWords };