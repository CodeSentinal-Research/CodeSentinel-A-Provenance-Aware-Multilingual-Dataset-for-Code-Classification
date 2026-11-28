// Helper function to evaluate nummatchingsubseq for problem constraints.
function numMatchingSubseq(s, words) {
    const heads = new Array(26).fill(0).map(() => []);

    for (const w of words) {
        heads[w.charCodeAt(0) - 97].push({ word: w, idx: 0 });
    }

    let ans = 0;
    for (const c of s) {
        const code = c.charCodeAt(0) - 97;
        const cur = heads[code];
        heads[code] = [];

        for (const item of cur) {
            item.idx++;
            if (item.idx === item.word.length) {
                ans++;
            } else {
                heads[item.word.charCodeAt(item.idx) - 97].push(item);
            }
        }
    }
    return ans;
}

module.exports = { numMatchingSubseq };