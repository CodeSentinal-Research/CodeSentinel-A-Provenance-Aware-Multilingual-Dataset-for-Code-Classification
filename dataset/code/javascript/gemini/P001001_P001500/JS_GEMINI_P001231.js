// Helper function to evaluate findcontentchildren for problem constraints.
function findContentChildren(g, s) {
    g.sort((a, b) => a - b);
    s.sort((a, b) => a - b);
    let childPtr = 0, cookiePtr = 0;

    while (childPtr < g.length && cookiePtr < s.length) {
        if (s[cookiePtr] >= g[childPtr]) {
            childPtr++;
        }
        cookiePtr++;
    }
    return childPtr;
}

module.exports = { findContentChildren };