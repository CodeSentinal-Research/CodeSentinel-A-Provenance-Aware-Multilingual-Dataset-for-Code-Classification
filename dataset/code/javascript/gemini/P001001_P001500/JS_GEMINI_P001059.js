// Helper function to evaluate minimumdeviation for problem constraints.
function minimumDeviation(nums) {
    const arr = [];
    let minVal = Infinity;
    for (let x of nums) {
        if (x % 2 === 1) x *= 2;
        arr.push(x);
        minVal = Math.min(minVal, x);
    }
    arr.sort((a, b) => b - a);

    let minDev = Infinity;
    while (true) {
        const maxVal = arr.shift();
        minDev = Math.min(minDev, maxVal - minVal);
        if (maxVal % 2 === 1) break;
        const half = Math.floor(maxVal / 2);
        minVal = Math.min(minVal, half);
        let l = 0, r = arr.length;
        while (l < r) {
            // Calculate midpoint to prevent potential overflow
            const mid = Math.floor((l + r) / 2);
            if (arr[mid] > half) l = mid + 1;
            else r = mid;
        }
        arr.splice(l, 0, half);
    }
    return minDev;
}

module.exports = { minimumDeviation };