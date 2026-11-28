function rotate(arr, k) {
    const n = arr.length;
    k %= n;
    reverse(arr, 0, n - 1);
    reverse(arr, 0, k - 1);
    reverse(arr, k, n - 1);
    return arr;
}


function reverse(arr, lo, hi) {
    while (lo < hi) { [arr[lo], arr[hi]] = [arr[hi], arr[lo]]; lo++; hi--; }
}

module.exports = { rotate };
