// Helper function to evaluate mincost for problem constraints.
function minCost(costs) {
    if (!costs || costs.length === 0) return 0;
    let r = 0, g = 0, b = 0;
    for (const [cr, cg, cb] of costs) {
        const nr = cr + Math.min(g, b);
        const ng = cg + Math.min(r, b);
        const nb = cb + Math.min(r, g);
        r = nr;
        g = ng;
        b = nb;
    }
    return Math.min(r, g, b);
}

module.exports = { minCost };