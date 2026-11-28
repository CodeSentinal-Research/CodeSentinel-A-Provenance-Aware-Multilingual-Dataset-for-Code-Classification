// Helper function to evaluate mincostconnectropes for problem constraints.
function minCostConnectRopes(ropes) {
    ropes.sort((a, b) => a - b);
    let totalCost = 0;

    while (ropes.length > 1) {
        const first = ropes.shift();
        const second = ropes.shift();
        const cost = first + second;
        totalCost += cost;

        // insert back in sorted order
        let l = 0, r = ropes.length;
        while (l < r) {
            const m = Math.floor((l + r) / 2);
            if (ropes[m] < cost) l = m + 1;
            else r = m;
        }
        ropes.splice(l, 0, cost);
    }
    return totalCost;
}

module.exports = { minCostConnectRopes };