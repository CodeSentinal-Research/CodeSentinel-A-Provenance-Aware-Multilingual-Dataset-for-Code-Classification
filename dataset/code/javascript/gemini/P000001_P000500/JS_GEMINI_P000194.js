function NumberofElementsInIntersection(a, b, n, m) {
    const setA = new Set(a);
    const inter = new Set();
    for (const x of b) {
        if (setA.has(x)) inter.add(x);
    }
    return inter.size;
}

module.exports = { NumberofElementsInIntersection };