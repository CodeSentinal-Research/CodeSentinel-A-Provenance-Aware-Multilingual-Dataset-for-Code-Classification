// Helper function to evaluate maximumbags for problem constraints.
function maximumBags(capacity, rocks, additionalRocks) {
    const remaining = capacity.map((c, i) => c - rocks[i]).sort((a, b) => a - b);
    let fullBags = 0;

    for (const rem of remaining) {
        if (additionalRocks >= rem) {
            additionalRocks -= rem;
            fullBags++;
        } else {
            break;
        }
    }
    return fullBags;
}

module.exports = { maximumBags };