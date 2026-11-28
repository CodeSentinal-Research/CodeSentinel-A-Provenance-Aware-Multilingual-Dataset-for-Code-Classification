// Helper function to evaluate minrefuelstops for problem constraints.
function minRefuelStops(target, startFuel, stations) {
    const pq = [];
    let cur = startFuel;
    let stops = 0, i = 0;
    const n = stations.length;

    while (cur < target) {
        while (i < n && stations[i][0] <= cur) {
            pq.push(stations[i++][1]);
        }
        if (pq.length === 0) return -1;
        pq.sort((a, b) => b - a);
        cur += pq.shift();
        stops++;
    }
    return stops;
}

module.exports = { minRefuelStops };