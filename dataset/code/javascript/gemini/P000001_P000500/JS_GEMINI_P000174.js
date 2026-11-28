function minDiff(arr) {
    arr.sort((a, b) => a - b);
    let minDiff = Infinity;
    for (let i = 1; i < arr.length; i++) {
        const diff = arr[i] - arr[i - 1];
        if (diff < minDiff) minDiff = diff;
    }
    return minDiff;
}

module.exports = { minDiff };