function arrayAverage(arr) {
    if (!arr || arr.length === 0) return 0.0;
    const sum = arr.reduce((acc, curr) => acc + curr, 0);
    return sum / arr.length;
}

module.exports = { arrayAverage };