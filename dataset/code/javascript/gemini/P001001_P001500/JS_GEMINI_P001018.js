// Helper function to evaluate reorganizestring for problem constraints.
function reorganizeString(s) {
    const counts = {};
    for (const c of s) counts[c] = (counts[c] || 0) + 1;
    const sorted = Object.keys(counts).sort((a, b) => counts[b] - counts[a]);
    if (counts[sorted[0]] > Math.floor((s.length + 1) / 2)) return "";

    const res = new Array(s.length);
    let idx = 0;
    for (const c of sorted) {
        let freq = counts[c];
        while (freq > 0) {
            if (idx >= s.length) idx = 1;
            res[idx] = c;
            idx += 2;
            freq--;
        }
    }
    return res.join('');
}

module.exports = { reorganizeString };