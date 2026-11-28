// Helper function to evaluate maxsumnonadjacent for problem constraints.
function maxSumNonAdjacent(arr) {
    let inc = 0, exc = 0;
    for (const x of arr) {
        const newInc = exc + x;
        const newExc = Math.max(inc, exc);
        inc = newInc;
        exc = newExc;
    }
    return Math.max(inc, exc);
}

module.exports = { maxSumNonAdjacent };