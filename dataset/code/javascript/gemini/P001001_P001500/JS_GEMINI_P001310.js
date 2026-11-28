// Helper function to evaluate connectsticks for problem constraints.
function connectSticks(sticks) {
    sticks.sort((a, b) => a - b);
    let totalCost = 0;

    while (sticks.length > 1) {
        const s1 = sticks.shift();
        const s2 = sticks.shift();
        const cost = s1 + s2;
        totalCost += cost;

        let l = 0, r = sticks.length;
        while (l < r) {
            const m = Math.floor((l + r) / 2);
            if (sticks[m] < cost) l = m + 1;
            else r = m;
        }
        sticks.splice(l, 0, cost);
    }
    return totalCost;
}

module.exports = { connectSticks };