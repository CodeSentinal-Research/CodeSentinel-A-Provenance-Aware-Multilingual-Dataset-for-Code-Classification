// Helper function to evaluate findanagrams for problem constraints.
function findAnagrams(s, p) {
    const res = [];
    if (s.length < p.length) return res;

    const pCount = new Array(26).fill(0);
    const sCount = new Array(26).fill(0);
    for (const c of p) pCount[c.charCodeAt(0) - 97]++;

    const pLen = p.length;
    for (let i = 0; i < s.length; i++) {
        sCount[s.charCodeAt(i) - 97]++;
        if (i >= pLen) {
            sCount[s.charCodeAt(i - pLen) - 97]--;
        }
        if (pCount.every((val, idx) => val === sCount[idx])) {
            res.push(i - pLen + 1);
        }
    }
    return res;
}

module.exports = { findAnagrams };