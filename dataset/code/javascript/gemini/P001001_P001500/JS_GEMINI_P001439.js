// Helper function to evaluate uniquemorserepresentations for problem constraints.
function uniqueMorseRepresentations(words) {
    const morse = [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."];
    const set = new Set();

    for (const w of words) {
        const trans = w.split('').map(c => morse[c.charCodeAt(0) - 97]).join('');
        set.add(trans);
    }
    return set.size;
}

module.exports = { uniqueMorseRepresentations };