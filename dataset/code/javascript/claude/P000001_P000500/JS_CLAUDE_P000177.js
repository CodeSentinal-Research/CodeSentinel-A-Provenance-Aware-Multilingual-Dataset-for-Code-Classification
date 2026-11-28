function findClosestElements(arr, k, x) {
    let l = 0, r = arr.length - k;
    while (l < r) {
        const mid = Math.floor((l + r) / 2);
        if (x - arr[mid] > arr[mid + k] - x) l = mid + 1;
        else r = mid;
    }
    return arr.slice(l, l + k);
}
module.exports = { findClosestElements };
