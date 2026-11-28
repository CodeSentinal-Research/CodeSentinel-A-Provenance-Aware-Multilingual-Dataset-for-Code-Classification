function getOddOccurrence(arr) {
    let res = 0;
    for (const x of arr) res ^= x;
    return res;
}

module.exports = { getOddOccurrence };