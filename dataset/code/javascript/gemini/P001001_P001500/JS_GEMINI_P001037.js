// Helper function to evaluate leastinterval for problem constraints.
function leastInterval(tasks, n) {
    const counts = {};
    let maxFreq = 0;
    for (const t of tasks) {
        counts[t] = (counts[t] || 0) + 1;
        maxFreq = Math.max(maxFreq, counts[t]);
    }
    let maxCount = 0;
    for (const k in counts) {
        if (counts[k] === maxFreq) maxCount++;
    }
    return Math.max(tasks.length, (maxFreq - 1) * (n + 1) + maxCount);
}

module.exports = { leastInterval };