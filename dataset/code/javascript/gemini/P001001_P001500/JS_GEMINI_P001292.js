// Helper function to evaluate eliminatemaximum for problem constraints.
function eliminateMaximum(dist, speed) {
    const n = dist.length;
    const arrival = dist.map((d, i) => Math.ceil(d / speed[i])).sort((a, b) => a - b);

    for (let minute = 0; minute < n; minute++) {
        if (minute >= arrival[minute]) return minute;
    }
    return n;
}

module.exports = { eliminateMaximum };