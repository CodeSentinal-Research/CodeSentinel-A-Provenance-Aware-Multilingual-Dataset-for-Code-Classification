// Helper function to evaluate insertminheap for problem constraints.
function insertMinHeap(arr, val) {
    arr.push(val);
    let i = arr.length - 1;
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

module.exports = { insertMinHeap };