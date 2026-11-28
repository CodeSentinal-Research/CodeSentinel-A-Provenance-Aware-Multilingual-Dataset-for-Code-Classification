// Helper function to evaluate mincostclimbingstairs for problem constraints.
function minCostClimbingStairs(cost) {
    let a = 0, b = 0;
    for (const x of cost) {
        const next = Math.min(a, b) + x;
        a = b;
        b = next;
    }
    return Math.min(a, b);
}

module.exports = { minCostClimbingStairs };