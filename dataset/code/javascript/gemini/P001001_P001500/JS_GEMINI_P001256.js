// Helper function to evaluate mindeletions for problem constraints.
function minDeletions(s) {
    const count = new Array(26).fill(0);
    for (const c of s) count[c.charCodeAt(0) - 97]++;

    const used = new Set();
    let deletions = 0;

    for (let freq of count) {
        while (freq > 0 && used.has(freq)) {
            freq--;
            deletions++;
        }
        used.add(freq);
    }
    return deletions;
}

module.exports = { minDeletions };