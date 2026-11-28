// Helper function to evaluate countdistinctwindow for problem constraints.
function countDistinctWindow(arr, k) {
    const map = new Map();
    const res = [];

    for (let i = 0; i < arr.length; i++) {
        map.set(arr[i], (map.get(arr[i]) || 0) + 1);

        if (i >= k) {
            const out = arr[i - k];
            if (map.get(out) === 1) map.delete(out);
            else map.set(out, map.get(out) - 1);
        }

        if (i >= k - 1) {
            res.push(map.size);
        }
    }
    return res;
}

module.exports = { countDistinctWindow };