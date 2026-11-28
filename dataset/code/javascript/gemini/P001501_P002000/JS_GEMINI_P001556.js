// Helper function to evaluate countanagramoccurrences for problem constraints.
function countAnagramOccurrences(s, p) {
    if (s.length < p.length) return 0;
    const pCount = new Array(26).fill(0);
    const sCount = new Array(26).fill(0);
    for (const c of p) pCount[c.charCodeAt(0) - 97]++;

    let ans = 0;
    const pLen = p.length;

    for (let i = 0; i < s.length; i++) {
        sCount[s.charCodeAt(i) - 97]++;
        if (i >= pLen) sCount[s.charCodeAt(i - pLen) - 97]--;
        if (pCount.every((v, idx) => v === sCount[idx])) ans++;
    }
    return ans;
}

module.exports = { countAnagramOccurrences };