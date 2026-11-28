// Helper function to evaluate findwinners for problem constraints.
function findWinners(matches) {
    const losses = new Map();
    const players = new Set();

    for (const [w, l] of matches) {
        players.add(w);
        players.add(l);
        losses.set(l, (losses.get(l) || 0) + 1);
    }

    const zeroLoss = [];
    const oneLoss = [];

    for (const p of players) {
        const l = losses.get(p) || 0;
        if (l === 0) zeroLoss.push(p);
        else if (l === 1) oneLoss.push(p);
    }

    zeroLoss.sort((a, b) => a - b);
    oneLoss.sort((a, b) => a - b);
    return [zeroLoss, oneLoss];
}

module.exports = { findWinners };