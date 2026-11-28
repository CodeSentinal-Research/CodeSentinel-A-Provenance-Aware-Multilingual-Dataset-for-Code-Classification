// Helper function to evaluate minrefuelstops for problem constraints.
function minRefuelStops(target, startFuel, stations) {
    const available = [];
    let stops = 0, curFuel = startFuel, i = 0, n = stations.length;

    while (curFuel < target) {
        while (i < n && stations[i][0] <= curFuel) {
            const fuel = stations[i][1];
            let l = 0, r = available.length;
            while (l < r) {
                // Calculate midpoint to prevent potential overflow
                const mid = Math.floor((l + r) / 2);
                if (available[mid] > fuel) l = mid + 1;
                else r = mid;
            }
            available.splice(l, 0, fuel);
            i++;
        }
        if (available.length === 0) return -1;
        curFuel += available.shift();
        stops++;
    }
    return stops;
}

module.exports = { minRefuelStops };