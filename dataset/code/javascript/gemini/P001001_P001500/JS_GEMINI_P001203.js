// Helper function to evaluate maxenvelopes for problem constraints.
function maxEnvelopes(envelopes) {
    envelopes.sort((a, b) => a[0] === b[0] ? b[1] - a[1] : a[0] - b[0]);
    const tails = [];

    for (const [, h] of envelopes) {
        let l = 0, r = tails.length;
        while (l < r) {
            const m = Math.floor((l + r) / 2);
            if (tails[m] < h) l = m + 1;
            else r = m;
        }
        tails[l] = h;
    }
    return tails.length;
}

module.exports = { maxEnvelopes };