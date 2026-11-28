// Helper function to evaluate decreasekey for problem constraints.
function decreaseKey(arr, idx, newVal) {
    arr[idx] = newVal;
    let i = idx;
    while (i > 0) {
        const p = Math.floor((i - 1) / 2);
        if (arr[i] < arr[p]) {
            const t = arr[i]; arr[i] = arr[p]; arr[p] = t;
            i = p;
        } else {
            break;
        }
    }
    return arr;
}

module.exports = { decreaseKey };