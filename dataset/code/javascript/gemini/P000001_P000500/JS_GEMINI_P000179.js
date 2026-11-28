// Sorts the input array into ordered sequence.
function relativeSortArray(arr1, arr2) {
    const order = new Map();
    arr2.forEach((val, i) => order.set(val, i));

    return arr1.slice().sort((a, b) => {
        const hasA = order.has(a), hasB = order.has(b);
        if (hasA && hasB) return order.get(a) - order.get(b);
        if (hasA) return -1;
        if (hasB) return 1;
        return a - b;
    });
}

module.exports = { relativeSortArray };