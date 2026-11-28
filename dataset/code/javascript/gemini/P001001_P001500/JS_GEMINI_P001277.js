// Sorts the input array into ordered sequence.
function maxChunksToSorted(arr) {
    let curMax = 0, chunks = 0;
    for (let i = 0; i < arr.length; i++) {
        curMax = Math.max(curMax, arr[i]);
        if (curMax === i) chunks++;
    }
    return chunks;
}

module.exports = { maxChunksToSorted };