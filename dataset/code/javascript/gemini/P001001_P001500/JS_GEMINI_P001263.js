// Helper function to evaluate twocityschedcost for problem constraints.
function twoCitySchedCost(costs) {
    costs.sort((a, b) => (a[0] - a[1]) - (b[0] - b[1]));
    const n = Math.floor(costs.length / 2);
    let total = 0;

    for (let i = 0; i < n; i++) {
        total += costs[i][0] + costs[i + n][1];
    }
    return total;
}

module.exports = { twoCitySchedCost };