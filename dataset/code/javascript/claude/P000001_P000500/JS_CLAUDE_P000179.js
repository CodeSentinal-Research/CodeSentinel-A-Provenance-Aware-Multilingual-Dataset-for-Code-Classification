function relativeSortArray(arr1, arr2) {
    const order = new Map(arr2.map((v, i) => [v, i]));
    return [...arr1].sort((a, b) => {
        const ha = order.has(a), hb = order.has(b);
        if (ha && hb) return order.get(a) - order.get(b);
        if (ha) return -1;
        if (hb) return 1;
        return a - b;
    });
}
module.exports = { relativeSortArray };
