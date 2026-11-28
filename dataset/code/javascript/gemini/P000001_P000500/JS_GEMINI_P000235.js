function printZigZag(matrix) {
    const res = [];
    for (let i = 0; i < matrix.length; i++) {
        if (i % 2 === 0) {
            res.push(...matrix[i]);
        } else {
            res.push(...matrix[i].slice().reverse());
        }
    }
    return res;
}

module.exports = { printZigZag };