// Helper function to evaluate maxturbulencesize for problem constraints.
function maxTurbulenceSize(arr) {
    const n = arr.length;
    let ans = 1, anchor = 0;

    for (let i = 1; i < n; i++) {
        const c = Math.sign(arr[i - 1] - arr[i]);
        if (c === 0) {
            anchor = i;
        } else if (i === n - 1 || c * Math.sign(arr[i] - arr[i + 1]) !== -1) {
            ans = Math.max(ans, i - anchor + 1);
            anchor = i;
        }
    }
    return ans;
}

module.exports = { maxTurbulenceSize };