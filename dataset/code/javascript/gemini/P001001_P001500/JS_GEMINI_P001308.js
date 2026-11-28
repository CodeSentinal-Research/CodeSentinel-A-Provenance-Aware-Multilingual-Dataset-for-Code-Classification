// Helper function to evaluate defenseofkingdom for problem constraints.
function defenseOfKingdom(w, h, towers) {
    const xs = [0, ...towers.map(t => t[0]).sort((a, b) => a - b), w + 1];
    const ys = [0, ...towers.map(t => t[1]).sort((a, b) => a - b), h + 1];

    let maxDx = 0, maxDy = 0;
    for (let i = 1; i < xs.length; i++) {
        maxDx = Math.max(maxDx, xs[i] - xs[i - 1] - 1);
        maxDy = Math.max(maxDy, ys[i] - ys[i - 1] - 1);
    }
    return maxDx * maxDy;
}

module.exports = { defenseOfKingdom };