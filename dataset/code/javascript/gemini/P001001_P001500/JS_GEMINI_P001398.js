// Helper function to evaluate commonchars for problem constraints.
function commonChars(words) {
    const common = new Array(26).fill(Infinity);

    for (const w of words) {
        const count = new Array(26).fill(0);
        for (const c of w) count[c.charCodeAt(0) - 97]++;
        for (let i = 0; i < 26; i++) common[i] = Math.min(common[i], count[i]);
    }

    const res = [];
    for (let i = 0; i < 26; i++) {
        while (common[i]-- > 0) {
            res.push(String.fromCharCode(97 + i));
        }
    }
    return res;
}

module.exports = { commonChars };