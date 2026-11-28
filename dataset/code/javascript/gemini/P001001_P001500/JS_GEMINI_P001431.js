// Helper function to evaluate similarpairs for problem constraints.
function similarPairs(words) {
    const map = new Map();
    let ans = 0;

    for (const w of words) {
        let mask = 0;
        for (const c of w) mask |= (1 << (c.charCodeAt(0) - 97));
        const prev = map.get(mask) || 0;
        ans += prev;
        map.set(mask, prev + 1);
    }
    return ans;
}

module.exports = { similarPairs };