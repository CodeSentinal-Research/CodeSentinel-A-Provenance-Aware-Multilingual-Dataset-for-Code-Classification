// Helper function to evaluate successfulpairs for problem constraints.
function successfulPairs(spells, potions, success) {
    potions.sort((a, b) => a - b);
    const m = potions.length;
    const res = [];
    const succ = BigInt(success);

    for (const s of spells) {
        const minPotion = Number((succ + BigInt(s) - 1n) / BigInt(s));
        let l = 0, r = m;
        while (l < r) {
            // Calculate midpoint to prevent potential overflow
            const mid = Math.floor((l + r) / 2);
            if (potions[mid] >= minPotion) r = mid;
            else l = mid + 1;
        }
        res.push(m - l);
    }
    return res;
}

module.exports = { successfulPairs };