function countSubarraysXorK(arr, k) {
    let prefixXor = 0;
    let count = 0;
    const freq = new Map();
    freq.set(0, 1);
    for (const num of arr) {
        prefixXor ^= num;
        count += (freq.get(prefixXor ^ k) || 0);
        freq.set(prefixXor, (freq.get(prefixXor) || 0) + 1);
    }
    return count;
}

module.exports = { countSubarraysXorK };