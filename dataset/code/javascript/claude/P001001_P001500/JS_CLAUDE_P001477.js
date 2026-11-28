function twoPointer(arr, target) {
    let lo = 0, hi = arr.length - 1;
    while (lo < hi) {
        const sum = arr[lo] + arr[hi];
        if (sum === target) return [lo, hi];
        if (sum < target) lo++;
        else hi--;
    }
    return [-1, -1];
}

module.exports = { twoPointer };
