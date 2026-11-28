// Helper function to evaluate mincut for problem constraints.
function minCut(s) {
    const n = s.length;
    const cuts = Array.from({ length: n }, (_, i) => i);

    for (let i = 0; i < n; i++) {
        let l = i, r = i;
        while (l >= 0 && r < n && s[l] === s[r]) {
            cuts[r] = (l === 0) ? 0 : Math.min(cuts[r], cuts[l - 1] + 1);
            l--; r++;
        }
        l = i; r = i + 1;
        while (l >= 0 && r < n && s[l] === s[r]) {
            cuts[r] = (l === 0) ? 0 : Math.min(cuts[r], cuts[l - 1] + 1);
            l--; r++;
        }
    }
    return cuts[n - 1];
}

module.exports = { minCut };