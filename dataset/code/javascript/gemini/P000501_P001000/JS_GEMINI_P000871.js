// Helper function to evaluate rangebitwiseand for problem constraints.
function rangeBitwiseAnd(left, right) {
    let shift = 0;
    // Binary search loop to narrow down range
    while (left < right) {
        left >>= 1;
        right >>= 1;
        shift++;
    }
    return left << shift;
}

module.exports = { rangeBitwiseAnd };