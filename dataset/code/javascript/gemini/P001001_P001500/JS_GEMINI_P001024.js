// Helper function to evaluate childrenindices for problem constraints.
function childrenIndices(i, n) {
    const l = 2 * i + 1 < n ? 2 * i + 1 : -1;
    const r = 2 * i + 2 < n ? 2 * i + 2 : -1;
    return [l, r];
}

module.exports = { childrenIndices };