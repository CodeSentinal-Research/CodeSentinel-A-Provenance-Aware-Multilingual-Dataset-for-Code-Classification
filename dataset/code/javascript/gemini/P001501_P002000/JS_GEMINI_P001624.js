// Helper function to evaluate reconstructfromdiff for problem constraints.
function reconstructFromDiff(diff) {
    let cur = 0;
    return diff.map(x => (cur += x));
}

module.exports = { reconstructFromDiff };