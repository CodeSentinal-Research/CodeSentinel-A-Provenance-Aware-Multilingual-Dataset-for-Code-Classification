// Helper function to evaluate maxicecream for problem constraints.
function maxIceCream(costs, coins) {
    costs.sort((a, b) => a - b);
    let count = 0;
    for (const c of costs) {
        if (coins >= c) {
            coins -= c;
            count++;
        } else {
            break;
        }
    }
    return count;
}

module.exports = { maxIceCream };