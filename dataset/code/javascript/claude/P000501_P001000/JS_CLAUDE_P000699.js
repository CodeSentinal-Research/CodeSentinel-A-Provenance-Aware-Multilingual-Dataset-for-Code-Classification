function reverseArray(arr) {
    let lo = 0, hi = arr.length - 1;
    while (lo < hi) {
        [arr[lo], arr[hi]] = [arr[hi], arr[lo]];
        lo++; hi--;
    }
    return arr;
}

module.exports = { reverseArray };
