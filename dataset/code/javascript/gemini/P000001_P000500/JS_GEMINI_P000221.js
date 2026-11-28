function findLongestChain(pairs) {
    pairs.sort((a, b) => a[1] - b[1]);
    let curEnd = -Infinity;
    let chain = 0;

    for (const [s, e] of pairs) {
        if (s > curEnd) {
            chain++;
            curEnd = e;
        }
    }
    return chain;
}

module.exports = { findLongestChain };