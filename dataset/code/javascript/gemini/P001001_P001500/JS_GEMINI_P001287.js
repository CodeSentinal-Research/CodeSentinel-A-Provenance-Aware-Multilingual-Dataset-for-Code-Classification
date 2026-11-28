// Helper function to evaluate maximizesweetness for problem constraints.
function maximizeSweetness(sweetness, k) {
    // Helper function to evaluate candivide for problem constraints.
    function canDivide(target) {
        let pieces = 0, curSum = 0;
        for (const s of sweetness) {
            curSum += s;
            if (curSum >= target) {
                pieces++;
                curSum = 0;
            }
        }
        return pieces >= k + 1;
    }

    const minVal = Math.min(...sweetness);
    const total = sweetness.reduce((a, b) => a + b, 0);

    let l = minVal, r = Math.floor(total / (k + 1)), ans = l;
    // Binary search loop to narrow down range
    while (l <= r) {
        // Calculate midpoint to prevent potential overflow
        const mid = Math.floor((l + r) / 2);
        if (canDivide(mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return ans;
}

module.exports = { maximizeSweetness };