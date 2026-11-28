// Helper function to evaluate minimumeffort for problem constraints.
function minimumEffort(tasks) {
    tasks.sort((a, b) => (b[1] - b[0]) - (a[1] - a[0]));
    let curEnergy = 0, reqEnergy = 0;

    for (const [actual, min] of tasks) {
        if (curEnergy < min) {
            reqEnergy += min - curEnergy;
            curEnergy = min;
        }
        curEnergy -= actual;
    }
    return reqEnergy;
}

module.exports = { minimumEffort };