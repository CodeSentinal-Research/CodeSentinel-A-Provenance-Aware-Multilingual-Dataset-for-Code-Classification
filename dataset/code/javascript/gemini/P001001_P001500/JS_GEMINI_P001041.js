// Helper function to evaluate mincosttohireworkers for problem constraints.
function mincostToHireWorkers(quality, wage, k) {
    const workers = quality.map((q, i) => [wage[i] / q, q]).sort((a, b) => a[0] - b[0]);
    const heap = [];
    let qSum = 0, ans = Infinity;

    for (const [ratio, q] of workers) {
        let l = 0, r = heap.length;
        while (l < r) {
            // Calculate midpoint to prevent potential overflow
            const mid = Math.floor((l + r) / 2);
            if (heap[mid] > q) l = mid + 1;
            else r = mid;
        }
        heap.splice(l, 0, q);
        qSum += q;
        if (heap.length > k) {
            qSum -= heap.shift();
        }
        if (heap.length === k) {
            ans = Math.min(ans, qSum * ratio);
        }
    }
    return ans;
}

module.exports = { mincostToHireWorkers };