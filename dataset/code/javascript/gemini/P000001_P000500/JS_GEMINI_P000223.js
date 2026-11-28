function activitySelection(start, end, n) {
    const act = [];
    for (let i = 0; i < n; i++) act.push([start[i], end[i]]);
    act.sort((a, b) => a[1] - b[1]);

    let count = 0, lastEnd = -Infinity;
    for (const [s, e] of act) {
        if (s > lastEnd) {
            count++;
            lastEnd = e;
        }
    }
    return count;
}

module.exports = { activitySelection };