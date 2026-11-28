// Helper function to evaluate distringmatch for problem constraints.
function diStringMatch(s) {
    let lo = 0, hi = s.length;
    const res = [];

    for (const c of s) {
        if (c === 'I') res.push(lo++);
        else res.push(hi--);
    }
    res.push(lo);
    return res;
}

module.exports = { diStringMatch };