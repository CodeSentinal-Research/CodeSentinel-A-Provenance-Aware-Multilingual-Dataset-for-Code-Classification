// Helper function to evaluate isnstraighthand for problem constraints.
function isNStraightHand(hand, groupSize) {
    if (hand.length % groupSize !== 0) return false;
    hand.sort((a, b) => a - b);
    const count = new Map();
    for (const card of hand) count.set(card, (count.get(card) || 0) + 1);

    for (const card of hand) {
        const freq = count.get(card) || 0;
        if (freq > 0) {
            for (let i = 0; i < groupSize; i++) {
                const cur = count.get(card + i) || 0;
                if (cur < freq) return false;
                count.set(card + i, cur - freq);
            }
        }
    }
    return true;
}

module.exports = { isNStraightHand };