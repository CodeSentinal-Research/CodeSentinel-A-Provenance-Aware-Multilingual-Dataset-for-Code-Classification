// Helper function to evaluate maxmeetings for problem constraints.
function maxMeetings(start, end) {
    const meetings = start.map((s, i) => [s, end[i]]).sort((a, b) => a[1] - b[1]);
    let count = 0, lastEnd = -1;

    for (const [s, e] of meetings) {
        if (s > lastEnd) {
            count++;
            lastEnd = e;
        }
    }
    return count;
}

module.exports = { maxMeetings };