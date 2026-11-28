// Helper function to evaluate issamebstseq for problem constraints.
function isSameBSTSeq(a, b) {
    if (a.length !== b.length) return false;
    if (a.length === 0) return true;
    if (a[0] !== b[0]) return false;

    const leftA = a.slice(1).filter(x => x < a[0]);
    const rightA = a.slice(1).filter(x => x > a[0]);
    const leftB = b.slice(1).filter(x => x < b[0]);
    const rightB = b.slice(1).filter(x => x > b[0]);

    return isSameBSTSeq(leftA, leftB) && isSameBSTSeq(rightA, rightB);
}

module.exports = { isSameBSTSeq };