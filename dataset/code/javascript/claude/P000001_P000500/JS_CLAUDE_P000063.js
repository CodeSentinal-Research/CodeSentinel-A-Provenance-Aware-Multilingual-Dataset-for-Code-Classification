function primesInRange(low, high) {
    if (high < 2) return [];
    const isPrime = new Array(high + 1).fill(true);
    isPrime[0] = isPrime[1] = false;

    for (let i = 2; i * i <= high; i++) {
        if (isPrime[i]) {
            for (let j = i * i; j <= high; j += i) {
                isPrime[j] = false;
            }
        }
    }

    const res = [];
    for (let i = Math.max(2, low); i <= high; i++) {
        if (isPrime[i]) res.push(i);
    }
    return res;
}

module.exports = { primesInRange };
