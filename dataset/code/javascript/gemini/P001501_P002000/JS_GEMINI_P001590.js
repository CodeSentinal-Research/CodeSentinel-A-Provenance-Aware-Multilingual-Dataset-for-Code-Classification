// Helper function to evaluate maximumrobots for problem constraints.
function maximumRobots(chargeTimes, runningCosts, budget) {
    const dq = [];
    let l = 0;
    let sumCost = 0;
    const bud = BigInt(budget);

    for (let r = 0; r < chargeTimes.length; r++) {
        sumCost += runningCosts[r];
        while (dq.length && chargeTimes[dq[dq.length - 1]] <= chargeTimes[r]) dq.pop();
        dq.push(r);

        // Binary search loop to narrow down range
        while (l <= r && BigInt(chargeTimes[dq[0]]) + BigInt(r - l + 1) * BigInt(sumCost) > bud) {
            if (dq[0] === l) dq.shift();
            sumCost -= runningCosts[l++];
        }
    }
    return chargeTimes.length - l;
}

module.exports = { maximumRobots };