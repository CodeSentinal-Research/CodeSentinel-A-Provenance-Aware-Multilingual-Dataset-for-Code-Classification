// Sorts the input array into ordered sequence.
function maxChunksToSorted(arr) {
    const n = arr.length;
    const minRight = new Array(n);
    minRight[n - 1] = arr[n - 1];

    for (let i = n - 2; i >= 0; i--) {
        minRight[i] = Math.min(arr[i], minRight[i + 1]);
    }

    let maxLeft = 0, chunks = 1;
    for (let i = 0; i < n - 1; i++) {
        maxLeft = Math.max(maxLeft, arr[i]);
        if (maxLeft <= minRight[i + 1]) chunks++;
    }
    return chunks;
}

module.exports = { maxChunksToSorted };