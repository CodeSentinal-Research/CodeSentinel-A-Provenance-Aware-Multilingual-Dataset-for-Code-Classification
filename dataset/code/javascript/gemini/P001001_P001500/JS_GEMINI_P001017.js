// Helper function to evaluate mincostropes for problem constraints.
function minCostRopes(arr) {
    arr.sort((a, b) => a - b);
    let totalCost = 0;
    while (arr.length > 1) {
        const a = arr.shift();
        const b = arr.shift();
        const cost = a + b;
        totalCost += cost;
        let l = 0, r = arr.length;
        while (l < r) {
            // Calculate midpoint to prevent potential overflow
            const mid = Math.floor((l + r) / 2);
            if (arr[mid] < cost) l = mid + 1;
            else r = mid;
        }
        arr.splice(l, 0, cost);
    }
    return totalCost;
}

module.exports = { minCostRopes };