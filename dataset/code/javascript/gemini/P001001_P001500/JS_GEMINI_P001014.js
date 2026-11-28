// Sorts the input array into ordered sequence.
function mergeKSortedArrays(arrays) {
    const res = [];
    for (const arr of arrays) {
        res.push(...arr);
    }
    return res.sort((a, b) => a - b);
}

module.exports = { mergeKSortedArrays };