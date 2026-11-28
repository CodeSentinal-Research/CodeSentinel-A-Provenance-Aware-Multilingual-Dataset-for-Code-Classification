// Helper function to evaluate numberofweeks for problem constraints.
function numberOfWeeks(milestones) {
    let total = 0n, maxVal = 0n;
    for (const m of milestones) {
        const val = BigInt(m);
        total += val;
        if (val > maxVal) maxVal = val;
    }
    const rest = total - maxVal;

    if (maxVal > rest + 1n) {
        return Number(2n * rest + 1n);
    }
    return Number(total);
}

module.exports = { numberOfWeeks };