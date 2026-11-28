// Helper function to evaluate minmeetingrooms for problem constraints.
function minMeetingRooms(intervals) {
    if (!intervals || intervals.length === 0) return 0;
    intervals.sort((a, b) => a[0] - b[0]);
    const pq = [];

    for (const [s, e] of intervals) {
        if (pq.length > 0 && pq[0] <= s) {
            pq.shift();
        }
        // insert into sorted
        let l = 0, r = pq.length;
        while (l < r) {
            const m = Math.floor((l + r) / 2);
            if (pq[m] < e) l = m + 1;
            else r = m;
        }
        pq.splice(l, 0, e);
    }
    return pq.length;
}

module.exports = { minMeetingRooms };