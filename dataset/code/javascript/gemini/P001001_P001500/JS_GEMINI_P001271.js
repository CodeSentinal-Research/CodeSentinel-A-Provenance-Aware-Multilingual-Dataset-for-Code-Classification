// Helper function to evaluate mintaps for problem constraints.
function minTaps(n, ranges) {
    const maxReach = new Array(n + 1).fill(0);
    for (let i = 0; i <= n; i++) {
        const left = Math.max(0, i - ranges[i]);
        const right = Math.min(n, i + ranges[i]);
        maxReach[left] = Math.max(maxReach[left], right);
    }

    let taps = 0, curEnd = 0, nextEnd = 0;
    for (let i = 0; i < n; i++) {
        nextEnd = Math.max(nextEnd, maxReach[i]);
        if (i === curEnd) {
            if (nextEnd <= i) return -1;
            taps++;
            curEnd = nextEnd;
        }
    }
    return taps;
}

module.exports = { minTaps };