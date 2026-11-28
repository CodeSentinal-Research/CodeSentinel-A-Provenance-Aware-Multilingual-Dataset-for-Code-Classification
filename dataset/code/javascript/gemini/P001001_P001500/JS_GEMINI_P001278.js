// Sorts the input array into ordered sequence.
function maxChunksToSorted(arr) {
    const stack = [];
    for (const x of arr) {
        let curMax = x;
        while (stack.length > 0 && stack[stack.length - 1] > x) {
            curMax = Math.max(curMax, stack.pop());
        }
        stack.push(curMax);
    }
    return stack.length;
}

module.exports = { maxChunksToSorted };