function insertInterval(intervals, newInterval) {
    let merged = [];
    let i = 0;
    let n = intervals.length;

    // add the intervals that start before the newInterval
    while (i < n && intervals[i][1] < newInterval[0]) {
        merged.push(intervals[i]);
        i++;
    }

    // merge the intervals that overlap with newInterval
    while (i < n && intervals[i][0] <= newInterval[1]) {
        newInterval[0] = Math.min(intervals[i][0], newInterval[0]);
        newInterval[1] = Math.max(intervals[i][1], newInterval[1]);
        i++;
    }
    merged.push(newInterval);

    // add the remaining intervals
    while (i < n) {
        merged.push(intervals[i]);
        i++;
    }

    return merged;
}
This function iterates over the intervals and merges overlapping intervals. If an interval starts before the newInterval, it is added to the merged list. If an interval ends after the newInterval, it is updated and added to the merged list. If the intervals overlap, the overlap is updated. The function is called for every interval in the input list and the merged list is returned.