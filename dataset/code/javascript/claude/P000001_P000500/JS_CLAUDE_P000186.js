function getMaxLen(nums) {
    let pos = 0, neg = 0, best = 0;
    for (const x of nums) {
        if (x === 0) { pos = neg = 0; }
        else if (x > 0) { pos++; neg = neg > 0 ? neg+1 : 0; }
        else { const np = neg > 0 ? neg+1 : 0; neg = pos+1; pos = np; }
        best = Math.max(best, pos);
    }
    return best;
}
module.exports = { getMaxLen };
