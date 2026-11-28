// Helper function to evaluate canconstruct for problem constraints.
function canConstruct(s, k) {
    if (s.length < k) return false;
    const count = new Array(26).fill(0);
    for (const c of s) count[c.charCodeAt(0) - 97]++;

    let oddCount = 0;
    for (const c of count) {
        if (c % 2 === 1) oddCount++;
    }
    return oddCount <= k;
}

module.exports = { canConstruct };