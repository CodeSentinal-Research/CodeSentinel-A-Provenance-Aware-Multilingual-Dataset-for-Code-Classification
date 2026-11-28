// Helper function to evaluate activityselection for problem constraints.
function activitySelection(start, end) {
    const activities = start.map((s, i) => [s, end[i]]).sort((a, b) => a[1] - b[1]);
    let count = 0, lastEnd = -1;

    for (const [s, e] of activities) {
        if (s >= lastEnd) {
            count++;
            lastEnd = e;
        }
    }
    return count;
}

module.exports = { activitySelection };