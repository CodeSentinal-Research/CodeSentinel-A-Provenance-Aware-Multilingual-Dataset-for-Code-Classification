// Helper function to evaluate maxdisttoclosest for problem constraints.
function maxDistToClosest(seats) {
    const n = seats.length;
    let lastPerson = -1, maxDist = 0;

    for (let i = 0; i < n; i++) {
        if (seats[i] === 1) {
            if (lastPerson === -1) {
                maxDist = i;
            } else {
                maxDist = Math.max(maxDist, Math.floor((i - lastPerson) / 2));
            }
            lastPerson = i;
        }
    }
    maxDist = Math.max(maxDist, n - 1 - lastPerson);
    return maxDist;
}

module.exports = { maxDistToClosest };