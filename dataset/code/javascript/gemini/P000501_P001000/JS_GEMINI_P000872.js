// Helper function to evaluate findmaximumxor for problem constraints.
function findMaximumXOR(nums) {
    let maxXor = 0, mask = 0;
    for (let i = 31; i >= 0; i--) {
        mask |= (1 << i);
        const prefixes = new Set();
        for (const num of nums) {
            prefixes.add(num & mask);
        }
        const greedyTarget = maxXor | (1 << i);
        for (const p of prefixes) {
            if (prefixes.has(p ^ greedyTarget)) {
                maxXor = greedyTarget;
                break;
            }
        }
    }
    return maxXor;
}

module.exports = { findMaximumXOR };