// Helper function to evaluate optimalmerge for problem constraints.
function optimalMerge(files) {
    files.sort((a, b) => a - b);
    let totalCost = 0;

    while (files.length > 1) {
        const f1 = files.shift();
        const f2 = files.shift();
        const cost = f1 + f2;
        totalCost += cost;

        let l = 0, r = files.length;
        while (l < r) {
            const m = Math.floor((l + r) / 2);
            if (files[m] < cost) l = m + 1;
            else r = m;
        }
        files.splice(l, 0, cost);
    }
    return totalCost;
}

module.exports = { optimalMerge };