function countEqualPosNegSubarrays(arr) {
    let prefixSum = 0;
    let count = 0;
    const freq = new Map();
    freq.set(0, 1);
    for (const x of arr) {
        const val = x > 0 ? 1 : (x < 0 ? -1 : 0);
        prefixSum += val;
        count += (freq.get(prefixSum) || 0);
        freq.set(prefixSum, (freq.get(prefixSum) || 0) + 1);
    }
    return count;
}

module.exports = { countEqualPosNegSubarrays };