function factorial(n) {
    let res = 1n;
    for (let i = 2n; i <= BigInt(n); i++) {
        res *= i;
    }
    return Number(res);
}

module.exports = { factorial };
