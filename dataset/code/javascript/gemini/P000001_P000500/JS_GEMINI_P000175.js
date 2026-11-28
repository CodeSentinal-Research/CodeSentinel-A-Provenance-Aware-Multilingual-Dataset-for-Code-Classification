function convertToWave(n, a) {
    for (let i = 0; i < n - 1; i += 2) {
        const temp = a[i];
        a[i] = a[i + 1];
        a[i + 1] = temp;
    }
}

module.exports = { convertToWave };