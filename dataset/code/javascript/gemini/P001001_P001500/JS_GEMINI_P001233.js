// Helper function to evaluate fractionalknapsack for problem constraints.
function fractionalKnapsack(w, values, weights) {
    const items = values.map((v, i) => [v, weights[i]]).sort((a, b) => (b[0] / b[1]) - (a[0] / a[1]));
    let totalVal = 0.0;
    let cap = w;

    for (const [val, wt] of items) {
        if (cap >= wt) {
            totalVal += val;
            cap -= wt;
        } else {
            totalVal += val * (cap / wt);
            break;
        }
    }
    return totalVal;
}

module.exports = { fractionalKnapsack };