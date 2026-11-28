// Helper function to evaluate insert for problem constraints.
function insert(intervals, newInterval) {
    const res = [];
    let i = 0;
    const n = intervals.length;

    while (i < n && intervals[i][1] < newInterval[0]) {
        res.push(intervals[i++]);
    }

    while (i < n && intervals[i][0] <= newInterval[1]) {
        newInterval[0] = Math.min(newInterval[0], intervals[i][0]);
        newInterval[1] = Math.max(newInterval[1], intervals[i][1]);
        i++;
    }
    res.push(newInterval);

    while (i < n) {
        res.push(intervals[i++]);
    }

    return res;
}

module.exports = { insert };