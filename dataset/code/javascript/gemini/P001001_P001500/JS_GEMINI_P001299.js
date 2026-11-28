// Helper function to evaluate minimumtime for problem constraints.
function minimumTime(time, totalTrips) {
    const minT = BigInt(Math.min(...time));
    let l = 1n, r = minT * BigInt(totalTrips), ans = r;

    // Binary search loop to narrow down range
    while (l <= r) {
        // Calculate midpoint to prevent potential overflow
        const mid = (l + r) / 2n;
        let trips = 0n;
        for (const t of time) {
            trips += mid / BigInt(t);
        }

        if (trips >= BigInt(totalTrips)) {
            ans = mid;
            r = mid - 1n;
        } else {
            l = mid + 1n;
        }
    }
    return Number(ans);
}

module.exports = { minimumTime };