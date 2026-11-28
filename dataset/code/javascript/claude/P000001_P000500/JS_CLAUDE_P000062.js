function isStrong(n) {
    if (n <= 0) return false;
    const fact = [1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880];
    let temp = n, sum = 0;
    while (temp > 0) {
        sum += fact[temp % 10];
        temp = Math.floor(temp / 10);
    }
    return sum === n;
}

module.exports = { isStrong };
