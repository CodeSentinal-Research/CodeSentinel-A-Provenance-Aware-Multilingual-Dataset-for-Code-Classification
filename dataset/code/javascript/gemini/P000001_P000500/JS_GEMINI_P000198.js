function areElementsContiguous(arr) {
    const set = new Set(arr);
    let minV = Infinity, maxV = -Infinity;
    for (const x of arr) {
        if (x < minV) minV = x;
        if (x > maxV) maxV = x;
    }
    return (maxV - minV + 1) === set.size;
}

module.exports = { areElementsContiguous };