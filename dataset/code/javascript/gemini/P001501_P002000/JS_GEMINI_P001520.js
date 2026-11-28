// Sorts the input array into ordered sequence.
function maxChunksToSorted(arr) {
    let maxSeen = 0, chunks = 0;
    for (let i = 0; i < arr.length; i++) {
        maxSeen = Math.max(maxSeen, arr[i]);
        if (maxSeen === i) chunks++;
    }
    return chunks;
}

module.exports = { maxChunksToSorted };