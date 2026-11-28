function printNosReverse(n) {
    const res = [];
    for (let i = n; i >= 1; i--) res.push(i);
    return res;
}

module.exports = { printNosReverse };
