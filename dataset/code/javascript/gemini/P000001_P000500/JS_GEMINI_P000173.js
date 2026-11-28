function maxDiff(arr) {
    if (arr.length < 2) return 0;
    let minVal = arr[0];
    let maxDiff = arr[1] - arr[0];

    for (let i = 1; i < arr.length; i++) {
        if (arr[i] - minVal > maxDiff) maxDiff = arr[i] - minVal;
        if (arr[i] < minVal) minVal = arr[i];
    }
    return maxDiff;
}

module.exports = { maxDiff };