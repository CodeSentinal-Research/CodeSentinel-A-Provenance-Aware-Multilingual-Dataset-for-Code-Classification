// Helper function to evaluate isisomorphic for problem constraints.
function isIsomorphic(s, t) {
    const m1 = new Array(256).fill(0);
    const m2 = new Array(256).fill(0);
    for (let i = 0; i < s.length; i++) {
        const c1 = s.charCodeAt(i);
        const c2 = t.charCodeAt(i);
        if (m1[c1] !== m2[c2]) return false;
        m1[c1] = i + 1;
        m2[c2] = i + 1;
    }
    return true;
}

module.exports = { isIsomorphic };