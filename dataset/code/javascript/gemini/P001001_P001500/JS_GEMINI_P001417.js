// Sorts the input array into ordered sequence.
function relativeSortArray(arr1, arr2) {
    const rank = new Map();
    arr2.forEach((v, i) => rank.set(v, i));

    return arr1.sort((a, b) => {
        const rA = rank.has(a) ? rank.get(a) : 1000 + a;
        const rB = rank.has(b) ? rank.get(b) : 1000 + b;
        return rA - rB;
    });
}

module.exports = { relativeSortArray };