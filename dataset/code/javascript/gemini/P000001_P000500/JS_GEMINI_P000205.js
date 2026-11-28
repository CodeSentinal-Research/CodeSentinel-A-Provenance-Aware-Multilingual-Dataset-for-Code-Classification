function getMedian(arr1, arr2) {
    const merged = arr1.concat(arr2).sort((a, b) => a - b);
    const n = merged.length;
    return (merged[n / 2 - 1] + merged[n / 2]) / 2.0;
}

module.exports = { getMedian };