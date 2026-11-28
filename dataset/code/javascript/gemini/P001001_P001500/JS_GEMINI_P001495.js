// Helper function to evaluate appendcharacters for problem constraints.
function appendCharacters(s, t) {
    let j = 0;
    for (let i = 0; i < s.length && j < t.length; i++) {
        if (s[i] === t[j]) j++;
    }
    return t.length - j;
}

module.exports = { appendCharacters };