// Helper function to evaluate maxdisttoclosest for problem constraints.
function maxDistToClosest(seats) {
    const n = seats.length;
    let prev = -1, maxDist = 0;

    for (let i = 0; i < n; i++) {
        if (seats[i] === 1) {
            if (prev === -1) maxDist = i;
            else maxDist = Math.max(maxDist, Math.floor((i - prev) / 2));
            prev = i;
        }
    }
    return Math.max(maxDist, n - 1 - prev);
}

module.exports = { maxDistToClosest };