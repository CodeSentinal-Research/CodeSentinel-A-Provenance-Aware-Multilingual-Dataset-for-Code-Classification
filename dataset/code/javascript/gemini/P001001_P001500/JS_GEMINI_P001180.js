// Helper function to evaluate vacationplanning for problem constraints.
function vacationPlanning(n, activities) {
    let [a, b, c] = activities[0];

    for (let i = 1; i < n; i++) {
        const [x, y, z] = activities[i];
        const na = x + Math.max(b, c);
        const nb = y + Math.max(a, c);
        const nc = z + Math.max(a, b);
        a = na;
        b = nb;
        c = nc;
    }
    return Math.max(a, b, c);
}

module.exports = { vacationPlanning };