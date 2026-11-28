// Helper function to evaluate maxevents for problem constraints.
function maxEvents(events) {
    events.sort((a, b) => a[0] - b[0]);
    const pq = [];
    let day = 0, count = 0, i = 0, n = events.length;

    while (i < n || pq.length > 0) {
        if (pq.length === 0) {
            day = events[i][0];
        }
        while (i < n && events[i][0] <= day) {
            // insert in sorted order
            const end = events[i++][1];
            let l = 0, r = pq.length;
            while (l < r) {
                const m = Math.floor((l + r) / 2);
                if (pq[m] < end) l = m + 1;
                else r = m;
            }
            pq.splice(l, 0, end);
        }
        pq.shift();
        count++;
        day++;
        while (pq.length > 0 && pq[0] < day) {
            pq.shift();
        }
    }
    return count;
}

module.exports = { maxEvents };