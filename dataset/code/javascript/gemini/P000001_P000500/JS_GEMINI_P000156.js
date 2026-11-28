function maxConsecutiveZeros(nums) {
    let maxZeros = 0, curZeros = 0;
    for (const x of nums) {
        if (x === 0) {
            curZeros++;
            if (curZeros > maxZeros) maxZeros = curZeros;
        } else {
            curZeros = 0;
        }
    }
    return maxZeros;
}

module.exports = { maxConsecutiveZeros };