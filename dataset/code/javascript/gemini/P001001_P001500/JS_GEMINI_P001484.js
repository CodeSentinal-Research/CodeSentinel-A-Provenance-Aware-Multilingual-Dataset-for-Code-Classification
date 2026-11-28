// Helper function to evaluate longestmountain for problem constraints.
function longestMountain(arr) {
    const n = arr.length;
    let ans = 0, base = 0;

    while (base < n) {
        let end = base;
        if (end + 1 < n && arr[end] < arr[end + 1]) {
            while (end + 1 < n && arr[end] < arr[end + 1]) end++;
            if (end + 1 < n && arr[end] > arr[end + 1]) {
                while (end + 1 < n && arr[end] > arr[end + 1]) end++;
                ans = Math.max(ans, end - base + 1);
            }
        }
        base = Math.max(end, base + 1);
    }
    return ans;
}

module.exports = { longestMountain };