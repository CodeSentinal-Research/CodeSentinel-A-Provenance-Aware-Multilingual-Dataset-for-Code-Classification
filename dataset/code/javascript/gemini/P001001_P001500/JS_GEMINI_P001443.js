// Helper function to evaluate wordcount for problem constraints.
function wordCount(startWords, targetWords) {
    const seen = new Set();
    for (const w of startWords) {
        let mask = 0;
        for (const c of w) mask |= (1 << (c.charCodeAt(0) - 97));
        seen.add(mask);
    }

    let ans = 0;
    for (const w of targetWords) {
        let mask = 0;
        for (const c of w) mask |= (1 << (c.charCodeAt(0) - 97));
        for (const c of w) {
            if (seen.has(mask ^ (1 << (c.charCodeAt(0) - 97)))) {
                ans++;
                break;
            }
        }
    }
    return ans;
}

module.exports = { wordCount };