// Helper function to evaluate huffmancost for problem constraints.
function huffmanCost(freq) {
    freq.sort((a, b) => a - b);
    let totalCost = 0;

    while (freq.length > 1) {
        const f1 = freq.shift();
        const f2 = freq.shift();
        const cost = f1 + f2;
        totalCost += cost;

        let l = 0, r = freq.length;
        while (l < r) {
            const m = Math.floor((l + r) / 2);
            if (freq[m] < cost) l = m + 1;
            else r = m;
        }
        freq.splice(l, 0, cost);
    }
    return totalCost;
}

module.exports = { huffmanCost };