function getMultiplicationTable(n, limit = 10) {
    const res = [];
    for (let i = 1; i <= limit; i++) {
        res.push(n * i);
    }
    return res;
}

module.exports = { getMultiplicationTable };
